/*
============================================================================================
File Name : 27.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 27. Write a program to receive messages from the message queue.
                    a. with 0 as a flag
                    b. with IPC_NOWAIT as a flag
Data : 19/09/2024
============================================================================================
*/



// program to send message to the queue
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msqid;
    struct message msg;

    // Generate a unique key and get the message queue ID
    key = ftok("file27", 65);
    msqid = msgget(key, 0666 | IPC_CREAT);

    // Prepare the message
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello, this is a message by program 27. ");

    // Send the message
    msgsnd(msqid, &msg, sizeof(msg.msg_text), 0);
    printf("Message sent to the queue.\n");

    return 0;
}