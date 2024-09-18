/*
============================================================================================
File Name : 18.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 18. Write a program to find out total number of directories on the pwd.
                    execute ls -l | grep ^d | wc ? Use only dup2.
Data : 18/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];

    // Create first pipe
    pipe(fd1);

    if (fork() == 0) {  // First child: 'ls -l'
        close(fd1[0]);  // Close read end of the pipe
        dup2(fd1[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(fd1[1]);  // Close original write end
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");  // Error handling
        return 1;
    } 

    // Create second pipe
    pipe(fd2);

    if (fork() == 0) {  // Second child: 'grep ^d'
        close(fd1[1]);  // Close write end of the first pipe
        dup2(fd1[0], STDIN_FILENO);  // Redirect stdin to pipe
        close(fd1[0]);  // Close original read end
        
        close(fd2[0]);  // Close read end of the second pipe
        dup2(fd2[1], STDOUT_FILENO);  // Redirect stdout to second pipe
        close(fd2[1]);  // Close original write end
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");  // Error handling
        return 1;
    } 

    // Parent process
    close(fd1[0]);  // Close all pipe ends in the parent
    close(fd1[1]);
    close(fd2[1]);

    // Execute 'wc -l' to count lines from the output of grep
    dup2(fd2[0], STDIN_FILENO);  // Redirect stdin to read end of the second pipe
    close(fd2[0]);  // Close original read end
    execlp("wc", "wc", "-l", NULL);      // this will return only the no of directoyry --> ls -l | grep ^d |wc -l
//        execlp("wc", "wc", NULL);  this will return the three values that are given when we type --> ls -l |grep ^d|wc
    
    perror("execlp wc");  // Error handling

    // Wait for all child processes to complete
    wait(NULL);  // Wait for the 'ls' process to complete
    wait(NULL);  // Wait for the 'grep' process to complete

    return 0;
}
