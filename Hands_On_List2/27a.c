/*
============================================================================================
File Name : 27a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 27. Write a program to receive messages from the message queue.
                    a. with 0 as a flag
                    b. with IPC_NOWAIT as a flag
Data : 19/09/2024
============================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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

    // Receive the message
    msgrcv(msqid, &msg, sizeof(msg.msg_text), 1, 0);
    printf("Message received: %s\n", msg.msg_text);

    return 0;
}

//    ipcrm -q <msqid> to delete the meaasage 
// ipcs -q   // to see all the message that are send to queue

/*
Explanation:
1. `msgrcv()` receives the message from the queue. The message type is set to 1.
2. The flag `0` ensures that the program waits for a message if the queue is empty.
3. The message content is printed after it's received.

For more details, use the following man pages:
- man 2 msgrcv
- man 2 ftok
- man 2 msgget
*/
