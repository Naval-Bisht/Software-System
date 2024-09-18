/*
============================================================================================
File Name : 10b.c
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

// Signal handler for SIGFPE
void signalHandler(int signum) {
    printf("Caught signal %d (SIGFPE). Floating-point exception occurred.\n", signum);
    exit(signum);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = signalHandler;
    sa.sa_flags = 0; // No special flags
    sigemptyset(&sa.sa_mask); // Initialize signal set to empty

    // Register signal handler
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Cause a floating-point exception
    int x = 0;
    int y = 100 / x;  // This will cause a SIGFPE

    return 0;
}
