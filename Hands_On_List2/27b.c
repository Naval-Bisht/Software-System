/*
============================================================================================
File Name : 27b.c
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

    // Try to receive the message without waiting
    if (msgrcv(msqid, &msg, sizeof(msg.msg_text), 1, IPC_NOWAIT) == -1) {
        perror("msgrcv");
    } else {
        printf("Message received: %s\n", msg.msg_text);
    }

    return 0;
}

/*
Explanation:
1. `msgrcv()` is called with the `IPC_NOWAIT` flag, which causes it to return immediately if no message is available, instead of waiting.
2. If no message is present, `msgrcv()` returns -1 and sets `errno`, which is printed using `perror()`.

For more details, use the following man pages:
- man 2 msgrcv
- man 2 ftok
- man 2 msgget
*/
