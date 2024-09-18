/*
============================================================================================
File Name : 16.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 16. Write a program to send and receive data from parent to child vice versa.
                    Use two way communication.
Data : 18/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<signal.h>

int main() {
    int pipefd1[2], pipefd2[2];
    char buffer[128]; 
    const char *pm = "Hello from parent!";              // pm is parent message
    const char *cm = "Hello from child!";    // cm is child meaage

    // Create two pipes for two-way communication
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        return 1;
    }

    __pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        close(pipefd1[0]);  // Close unused read end of first pipe
        close(pipefd2[1]);  // Close unused write end of second pipe

        // Send message to child
        write(pipefd1[1], pm, strlen(pm) + 1);
        close(pipefd1[1]);  // Close write end after sending

        // Read response from child
        read(pipefd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(pipefd2[0]);  // Close read end after reading
    } 
    else if (pid == 0) {
        // Child process
        close(pipefd1[1]);  // Close unused write end of first pipe
        close(pipefd2[0]);  // Close unused read end of second pipe

        // Read message from parent
        read(pipefd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd1[0]);  // Close read end after reading

        // Send response to parent
        write(pipefd2[1], cm, strlen(cm) + 1);
        close(pipefd2[1]);  // Close write end after sending
    } 
    else {
        perror("fork");
        return 1;
    }

    return 0;
}

/*
Explanation:
1. Two pipes are created for two-way communication: one for the parent-to-child direction and another for child-to-parent.
2. The parent writes a message to the first pipe, and the child reads it.
3. The child then writes a response to the second pipe, which the parent reads.
4. Closing the unused ends of the pipes is crucial to avoid deadlock.

Alternative Approaches:
- You could implement two-way communication using Unix domain sockets or message queues for more complex data exchanges.
- Named pipes (FIFOs) are an option if the parent and child processes are unrelated.

For more details, use the following man pages:
- man 2 pipe
- man 2 fork
- man 7 mq_overview (for message queues)
- man 7 unix (for Unix domain sockets)
*/

