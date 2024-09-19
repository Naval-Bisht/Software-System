/*
============================================================================================
File Name : 32c.c
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

int main() {
    key_t key = ftok("file32", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, IPC_RMID);  // Remove semaphore
    printf("Semaphore removed\n");

    return 0;
}
