/*
============================================================================================
File Name : 10a.c
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
#include <unistd.h>

// Signal handler for SIGINT
void signalHandler(int signum) {
    printf("Caught signal %d (SIGINT). Interrupt signal received.\n", signum);
    exit(signum);
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = signalHandler;
    sa.sa_flags = 0; // No special flags
    sigemptyset(&sa.sa_mask); // Initialize signal set to empty

    // Register signal handler
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to wait for interrupt
    while (1) {
      //  pause(); // Wait for signal
    }

    return 0;
}
