/*
============================================================================================
File Name : 28a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Data : 19/09/2024
============================================================================================
*/

// first check the permisiion of the message using 
          // ipcs -q


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key = ftok("file28", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);  // Get message queue info
    buf.msg_perm.mode = 0664;       // Change permission
    msgctl(msgid, IPC_SET, &buf);   // Set new permissions
    // check the received mesage 
     if (msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT) == -1) {
        perror("No message available");
    } else {
        printf("Message received: %s\n", message.msg_text);
    }
    printf("Permissions changed to 0664\n");
    return 0;
}

// after exeutiong the program again check the permission using 
                        // ipcs -q



