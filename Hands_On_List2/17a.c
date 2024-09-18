/*
============================================================================================
File Name : 17a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 17. Write a program to execute ls -l | wc.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Data : 18/09/2024
============================================================================================
*/                            // dup 2

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);  // Create a pipe

    __pid_t pid = fork();

    if (pid == 0) {
        // Child process: Executes `wc`
        close(pipefd[1]);          // Close unused write end
        dup2(pipefd[0], STDIN_FILENO);  // Duplicate pipe's read end to stdin
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
    } else {
        // Parent process: Executes `ls -l`
        close(pipefd[0]);          // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO); // Duplicate pipe's write end to stdout
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    return 0;
}

/*
Explanation:
1. `dup2(pipefd[0], STDIN_FILENO)` duplicates the pipe's read end directly to stdin, replacing the old file descriptor.
2. Similarly, `dup2(pipefd[1], STDOUT_FILENO)` duplicates the pipe's write end directly to stdout.
3. This is a more explicit version of `dup()`, allowing you to specify the exact file descriptor.

For more details, use the following man pages:
- man 2 dup2
- man 2 pipe
- man 3 execlp
*/
