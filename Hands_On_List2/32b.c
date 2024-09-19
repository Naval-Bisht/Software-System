/*
============================================================================================
File Name : 32b.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 32. Write a program to implement semaphore to protect any critical section.
                    a. rewrite the ticket number creation program using semaphore
                    b. protect shared memory from concurrent write access
                    c. protect multiple pseudo resources ( may be two) using counting semaphore
                    d. remove the created semaphore
Data : 19/09/2024
============================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semid;

void sem_wait() {
    struct sembuf sb = {0, -1, 0};  // Decrease semaphore value (wait)
    semop(semid, &sb, 1);
}

void sem_signal() {
    struct sembuf sb = {0, 1, 0};  // Increase semaphore value (signal)
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("file32", 65);
    semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 2);  // Initialize counting semaphore for two resources

    for (int i = 0; i < 5; i++) {
        sem_wait();
        printf("Resource acquired by process %d\n", i);
        sem_signal();
    }

    return 0;
}
