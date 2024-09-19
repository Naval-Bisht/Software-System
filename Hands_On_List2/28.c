/*
============================================================================================
File Name : 28.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Data : 19/09/2024
============================================================================================
*/
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
    key = ftok("file28", 65);
    msqid = msgget(key, 0666 | IPC_CREAT);

    // Prepare the message
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello, this is a message by program 28. ");

    // Send the message
    msgsnd(msqid, &msg, sizeof(msg.msg_text), 0);
    printf("Message sent to the queue.\n");

    return 0;
}