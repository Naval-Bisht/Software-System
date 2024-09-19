/*
============================================================================================
File Name : 24.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 24. Write a program to create a message queue and print the key and message queue id.
Data : 19/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>  // For rand() and srand()
#include <string.h>
// first run the bash file by to create a file 
// $ bash 24.sh

int main() {
    key_t key;
    int msgid;
        int rn = rand() % 256;
    // Generate unique key
    key = ftok("progfile24", rn);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Message queue key: %d\n", key);
    printf("Message queue ID: %d\n", msgid);

    return 0;
}
