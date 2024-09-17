/*
============================================================================================
File Name : 8a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 8. Write a separate program using signal system call to catch the following signals.
                    a. SIGSEGV
                    b. SIGINT
                    c. SIGFPE
                    d. SIGALRM (use alarm system call)
                    e. SIGALRM (use setitimer system call)
                    f. SIGVTALRM (use setitimer system call)
                    g. SIGPROF (use setitimer system call)

Data : 16/09/2024
============================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGINT
void signalHandler(int signum) {
    printf("Caught signal %d (SIGINT). Interrupt signal received.\n", signum);
    exit(signum);
}

int main() {
    // Register signal handler
    signal(SIGINT, signalHandler);

    // Infinite loop to wait for interrupt
    while (1) {
        // Waiting for signal
    }

    return 0;
}


// man 7 signal
