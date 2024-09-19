/*
============================================================================================
File Name : 31.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore
Data : 19/09/2024
============================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("file31", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);  // Create semaphore

    semctl(semid, 0, SETVAL, 1);  // Initialize semaphore to 1 (binary semaphore)
    printf("Binary semaphore created and initialized successfully \n");

    return 0;
}
