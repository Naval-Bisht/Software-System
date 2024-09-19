/*
============================================================================================
File Name : 32a.c
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
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

int main() {
    key_t key = ftok("file32", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *data = (char *)shmat(shmid, NULL, 0);

    struct sembuf sb = {0, -1, 0};  // Wait operation

    printf("Waiting to write to shared memory...\n");
    semop(semid, &sb, 1);  // Enter critical section

    strcpy(data, "Protected Write to Shared Memory!");
    printf("Data written: %s\n", data);

    sb.sem_op = 1;  // Signal operation
    semop(semid, &sb, 1);  // Leave critical section

    shmdt(data);  // Detach shared memory
    return 0;
}
