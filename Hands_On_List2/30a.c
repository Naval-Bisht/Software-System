/*
============================================================================================
File Name : 30a.c
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

    // Generate the same key
    key = ftok("shmfile", 65);

    // Get the shared memory segment
    shmid = shmget(key, 1024, 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory in read-only mode
    shared_memory = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (shared_memory == (char*)-1) {
        perror("shmat");
        return 1;
    }

    // Try to overwrite data (this will fail due to read-only mode) //
    // it will faail and caude the segmentation fault

    printf("Attempting to write in read-only mode...\n");
    strcpy(shared_memory, "Attempt to overwrite.");
    printf("Data in shared memory: %s\n", shared_memory);

// 

    // Detach the shared memory
    shmdt(shared_memory);

    return 0;
}


// // we will get this error 
// naval@Tarantula:~/SOFTWARE SYSTEM/Hands_On_List2$ ./30a
// Attempting to write in read-only mode...
// Segmentation fault (core dumped)
// naval@Tarantula:~/SOFTWARE SYSTEM/Hands_On_List2$ ^C