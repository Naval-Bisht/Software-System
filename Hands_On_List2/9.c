/*
============================================================================================
File Name : 9.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 9. Write a program to ignore a SIGINT signal then reset the 
                    default action of the SIGINT signal - Use signal system call.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for SIGINT
void signal_handler(int signum) {
    printf("Caught SIGINT (Ctrl + C)\n");
}

int main() {
    // Ignore SIGINT signal
    signal(SIGINT, SIG_IGN);
    printf("SIGINT signal is ignored. Try pressing Ctrl + C.\n");
    sleep(5);

    // Reset to default action (terminate the program on SIGINT)
    signal(SIGINT, SIG_DFL);
    printf("SIGINT signal action reset to default. Try pressing Ctrl + C again.\n");

    // Wait for signal
    while (1) {
        pause();
    }

    return 0;
}

/*
Explanation:
1. signal(SIGINT, SIG_IGN): Ignores the SIGINT signal, which is typically triggered by pressing Ctrl + C in the terminal.
2. sleep(5): Pauses execution for 5 seconds to give the user a chance to trigger SIGINT.
3. signal(SIGINT, SIG_DFL): Resets the signal handler for SIGINT to its default action (terminate the program).
4. pause(): Waits for a signal to be delivered.

Alternative Approaches:
- Instead of using `signal()`, you can use `sigaction()` for finer control over signal handling.
- You can use `raise()` to programmatically raise a signal.

For more details, use the following man pages:
- man 2 signal
- man 3 raise
- man 2 sigaction
*/

