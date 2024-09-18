/*
============================================================================================
File Name : 13a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the
                     second program will send the signal (using kill system call). Find out 
                     whether the first program is able to catch the signal or not.
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = atoi(argv[1]);
    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);

    return 0;
}

/*
Explanation:
1. The program takes the PID of another process as an argument and sends it the `SIGSTOP` signal.
2. kill(pid, SIGSTOP): Sends the `SIGSTOP` signal to the specified process, which stops it from executing until it receives a `SIGCONT` signal.
3. `SIGSTOP` cannot be caught, blocked, or ignored by the target process.

For more details, use the following man pages:
- man 2 kill
- man 7 signal
*/
