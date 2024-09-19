/*
============================================================================================
File Name : 25.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                    a. access permission
                    b. uid, gid
                    c. time of last message sent and received
                    d. time of last change in the message queue
                    e. size of the queue
                    f. number of messages in the queue
                    g. maximum number of bytes allowed
                    h. pid of the msgsnd and msgrcv
Data : 19/09/2024
============================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main() {
    key_t key = ftok("progfile25", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);  // Get message queue info

    printf("Access permission: %o\n", buf.msg_perm.mode);
    printf("UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("Last sent message time: %ld\n", buf.msg_stime);
    printf("Last received message time: %ld\n", buf.msg_rtime);
    printf("Last change time: %ld\n", buf.msg_ctime);
    printf("Number of messages: %ld\n", buf.msg_qnum);
    printf("Maximum bytes allowed: %ld\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d, PID of last msgrcv: %d\n", buf.msg_lspid, buf.msg_lrpid);

    return 0;
}
