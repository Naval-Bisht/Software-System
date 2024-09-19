/*
============================================================================================
File Name : 29a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 29. Write a program to remove the message queue.
Data : 19/09/2024
============================================================================================
*/

// removing the meaage queue withoue the use of  // ipcrm -q <msqid>

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("file29", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    msgctl(msgid, IPC_RMID, NULL);  // Remove message queue
    printf("Message queue removed\n");

    return 0;
}
