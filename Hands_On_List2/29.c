/*
============================================================================================
File Name : 29.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 29. Write a program to remove the message queue.
Data : 19/09/2024
============================================================================================
*/

//  creating the queue
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msqid;

    // Generate a unique key
    key = ftok("file29", 65);

    // Create the message queue and get the message queue ID
    msqid = msgget(key, 0666 | IPC_CREAT);

    if (msqid < 0) {
        perror("msgget");
        return 1;
    }

    printf("Message queue created successfully with ID: %d\n", msqid);

    return 0;
}
