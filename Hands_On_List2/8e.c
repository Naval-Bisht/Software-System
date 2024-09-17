/*
============================================================================================
File Name : 8e.c
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
#include<unistd.h>

// Signal handler for SIGVTALRM
void signalHandler(int signum) {
    printf("Caught signal %d (SIGVTALRM). Virtual timer expired.\n", signum);
    exit(signum);
}

int main() {
    // Register signal handler
    signal(SIGVTALRM, signalHandler);

    // Set up virtual timer
    struct itimerval timer;
    timer.it_value.tv_sec = 2;  // Initial expiration time
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0;

    // Set virtual timer
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    

while(1){}

    return 0;
}


// man 7 signal
