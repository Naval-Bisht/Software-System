/*
============================================================================================
File Name : 30c.c
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

int main() {
    key_t key;
    int shmid;

    // Generate the same key
    key = ftok("shmfile", 65);

    // Get the shared memory segment
    shmid = shmget(key, 1024, 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }
    printf("Shared memory removed successfully.\n");

    return 0;
}
