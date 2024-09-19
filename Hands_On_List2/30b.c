/*
============================================================================================
File Name : 30b.c
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
    char *shared_memory;

    // Generate the same key
    key = ftok("shmfile", 65);

    // Get the shared memory segment
    shmid = shmget(key, 1024, 0666);
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

    // Detach the shared memory
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        return 1;
    }
    printf("Shared memory detached successfully.\n");

    return 0;
}
