/*
============================================================================================
File Name : 32.c
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
#include <stdio.h>
#include <fcntl.h>   // For open() and O_CREAT flag
#include <unistd.h>  // For close()
#include <errno.h>   // For errno and perror()

int semid;

void sem_wait() {
    struct sembuf sb = {0, -1, 0};  // Semaphore operation: wait
    semop(semid, &sb, 1);
}

void sem_signal() {
    struct sembuf sb = {0, 1, 0};  // Semaphore operation: signal
    semop(semid, &sb, 1);
}

int main() {

        int fd = open("file32", O_WRONLY | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        // Check if the file already exists or another error occurred
        if (errno == EEXIST) {
            printf("File already exists.\n");
        } else {
            perror("open");
        }
        return 1;
    }
    // Close the file
    close(fd);


    key_t key = ftok("file32", 65);
    semid = semget(key, 1, 0666 | IPC_CREAT);  // Create semaphore
    semctl(semid, 0, SETVAL, 1);  // Initialize to 1

    int ticket = 0;

    for (int i = 0; i < 5; i++) {
        sem_wait();
        ticket++;
        printf("Ticket number: %d\n", ticket);
        sem_signal();
    }

    return 0;
}
