/*
============================================================================================
File Name : 8.c
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
// segmentaation fault 



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGSEGV
void signalHandler(int signum) {
    fprintf(stderr, "Caught signal %d (SIGSEGV). Segmentation fault occurred.\n", signum);
    exit(signum);
}

int main() {
    // Register signal handler
    signal(SIGSEGV, signalHandler);

    // Cause a segmentation fault
    int *p = NULL;
    *p = 42;

    return 0;
}


// man 7 signal
