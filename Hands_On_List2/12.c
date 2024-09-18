/*
============================================================================================
File Name : 12.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 12. Write a program to create an orphan process. Use kill system call to send 
                    SIGKILL signal to the parent process from the child process
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process ID: %d\n", getpid());
        sleep(10);  // Parent sleeps for a while to ensure it can be killed
    } 
    else if (pid == 0) {
        // Child process
        sleep(2);  // Ensure parent is running
        printf("Child process sending SIGKILL to parent\n");
        kill(getppid(), SIGKILL);  // Send SIGKILL to parent
        printf("Child process is now orphaned, waiting for parent to die\n");
        sleep(5);  // Wait to demonstrate orphan status

    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*
Explanation:
1. fork(): Creates a new child process. If fork() returns 0, it means this is the child process.
2. kill(getppid(), SIGKILL): Child sends a SIGKILL signal to its parent, causing the parent to terminate.
3. The child becomes an orphan when the parent dies and is adopted by the init process (PID 1).
4. sleep(): Used to ensure timing between parent and child processes.

Alternative Approaches:
- Instead of sending SIGKILL, you could send other signals like SIGTERM or SIGSTOP to explore their effects.
- You could use `setsid()` to create a new session leader and explore process groups.

For more details, use the following man pages:
- man 2 fork
- man 2 kill
- man 2 setsid
*/
