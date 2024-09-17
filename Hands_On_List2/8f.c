/*
============================================================================================
File Name : 8f.c
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

// Signal handler for SIGPROF
void signalHandler(int signum) {
    printf("Caught signal %d (SIGPROF). Profiling timer expired.\n", signum);
    exit(signum);
}

int main() {
    // Register signal handler
    signal(SIGPROF, signalHandler);

    // Set up profiling timer
    struct itimerval timer;
    timer.it_value.tv_sec = 2;  // Initial expiration time
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No periodic timer
    timer.it_interval.tv_usec = 0;

    // Set profiling timer
    setitimer(ITIMER_PROF, &timer, NULL);

    // Pause to wait for signal
    while(1){}

    return 0;
}


// man 2 signal - For information on the signal function.
// man 2 alarm - For information on the alarm function.
// man 2 setitimer - For information on the setitimer function.
// man 7 signal - For a general overview of signals.
