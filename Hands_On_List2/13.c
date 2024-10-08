/*
============================================================================================
File Name : 13.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the
                     second program will send the signal (using kill system call). Find out 
                     whether the first program is able to catch the signal or not.
Data : 17/09/2024
============================================================================================
*/
// wait for sigstop
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Process waiting for SIGSTOP signal. PID: %d\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
      //  pause();  // Wait for any signal
    }

    return 0;
}

/*
Explanation:
1. pause(): Suspends the process until a signal is caught.
2. This program will not be able to catch `SIGSTOP` as it is one of the signals that cannot be caught or ignored.

For more details, use the following man pages:
- man 2 pause
- man 7 signal (to see a list of signals, including those that cannot be caught)
*/
