/*
============================================================================================
File Name : 17b.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 17. Write a program to execute ls -l | wc.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Data : 18/09/2024
============================================================================================
*/                                   // fcntl

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    pipe(pipefd);  // Create a pipe

    pid_t pid = fork();

    if (pid == 0) {
        // Child process: Executes `wc`
        close(pipefd[1]);  // Close unused write end
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);  // Duplicate pipe's read end to stdin
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
    } 
    else {
        // Parent process: Executes `ls -l`
        close(pipefd[0]);  // Close unused read end
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);  // Duplicate pipe's write end to stdout
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    return 0;
}

/*
Explanation:
1. `fcntl(pipefd[0], F_DUPFD, STDIN_FILENO)` duplicates the pipe's read end to stdin using the `fcntl()` system call.
2. `fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO)` duplicates the pipe's write end to stdout in the parent process.
3. `fcntl()` provides more control over file descriptors compared to `dup()` and `dup2()`.

For more details, use the following man pages:
- man 2 fcntl
- man 2 pipe
- man 3 execlp
*/
