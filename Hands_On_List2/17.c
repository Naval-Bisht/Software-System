/*
============================================================================================
File Name : 17.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 17. Write a program to execute ls -l | wc.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Data : 18/09/2024
============================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (wc)
        // Close the write end of the pipe, as wc only needs to read
        close(pipefd[1]);

        // Duplicate the read end of the pipe to stdin (fd 0)
        dup(pipefd[0]);

        // Close the original read end after duplicating
        close(pipefd[0]);

        // Execute the wc command
        execlp("wc", "wc", NULL);
        perror("execlp wc");  // Error handling if execlp fails
        exit(EXIT_FAILURE);
    } else {  // Parent process (ls -l)
        // Close the read end of the pipe, as ls only writes
        close(pipefd[0]);

        // Duplicate the write end of the pipe to stdout (fd 1)
        dup(pipefd[1]);

        // Close the original write end after duplicating
        close(pipefd[1]);

        // Execute the ls -l command
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");  // Error handling if execlp fails
        exit(EXIT_FAILURE);
    }

    // Wait for the child process to finish
    wait(NULL);

    return 0;
}
