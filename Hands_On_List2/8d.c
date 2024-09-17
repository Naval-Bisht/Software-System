/*
============================================================================================
File Name : 8d.c
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
#include <sys/time.h>
#include <unistd.h>


// Signal handler for SIGALRM
void signalHandler(int signum) {
    printf("Caught signal %d (SIGALRM). Alarm signal received for timer.\n", signum);
    exit(signum);
}

int main() {
    // Register signal handler
    signal(SIGALRM, signalHandler);

    // Set up itimer
    struct itimerval timer;
    timer.it_value.tv_sec = 2;  // Initial expiration time
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No periodic timer
    timer.it_interval.tv_usec = 0;

    // Set timer
    setitimer(ITIMER_REAL, &timer, NULL);

    // Pause to wait for signal
    pause();

    return 0;
}


// man 7 signal
