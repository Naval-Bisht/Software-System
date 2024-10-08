/*
============================================================================================
File Name : 10.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 10. Write a separate program using sigaction system call to catch the following signals.
                    a. SIGSEGV
                    b. SIGINT
                    c. SIGFPE
Data : 17/09/2024
============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler for SIGSEGV
void signalHandler(int signum) {
    printf("Caught signal %d (SIGSEGV). Segmentation fault occurred.\n", signum);
    exit(signum);
}

int main() {
    struct sigaction sag;

    // Set up the sigaction structure
    sag-flt.sa_handler = signalHandler;
    sag.sa_flags = 0; // No special flags
    sigemptyset(&sag.sa_mask); // Initialize signal set to empty

    // Register signal handler
    if (sigaction(SIGSEGV, &sag, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Cause a segmentation fault
    int *p = NULL;
    *p = 42;

    return 0;
}
