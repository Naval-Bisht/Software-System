/*
============================================================================================
File Name : 8b.c
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

// Signal handler for SIGFPE
void signalHandler(int signum) {
    fprintf(stderr, "Caught signal %d (SIGFPE). Floating-point exception occurred.\n", signum);
    exit(EXIT_FAILURE);
}

int main() {
    // Register signal handler
    signal(SIGFPE, signalHandler);

    // Cause a floating-point exception
    int x = 0;
    float y = 1000 / x;  // This will cause a SIGFPE
    printf("%f",y);


    return 0;
}



// man 7 signal
