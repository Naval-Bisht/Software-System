/*
============================================================================================
File Name : 30.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 30. Write a program to create a shared memory.
                    a. write some data to the shared memory
                    b. attach with O_RDONLY and check whether you are able to overwrite.
                    c. detach the shared memory
                    d. remove the shared memory
Data : 19/09/2024
============================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *shared_memory;

    // Generate a unique key
    key = ftok("shmfile", 65);

    // Create shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory to the process
    shared_memory = (char*) shmat(shmid, NULL, 0);
    if (shared_memory == (char*)-1) {
        perror("shmat");
        return 1;
    }

    // Write data to shared memory
    strcpy(shared_memory, "Hello, this is data written to shared memory.");
    printf("Data written to shared memory: %s\n", shared_memory);

    // Detach the shared memory
    shmdt(shared_memory);

    return 0;
}
