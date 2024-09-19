/*
============================================================================================
File Name : 23.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 23. Write a program to print the maximum number of files can be opened within a process 
                    and size of a pipe (circular buffer).
Data : 19/09/2024
============================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>   // For RLIMIT_NOFILE
#include <fcntl.h>          // For fcntl() and F_GETPIPE_SZ
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

// Define F_GETPIPE_SZ manually if it's not defined
#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032  // Common value for most Linux systems
#endif

int main() {
    struct rlimit rl;
    int pipe_fd;
    int pipe_size;

    // Get the maximum number of file descriptors that can be opened by a process
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("Maximum number of open files in a process: %ld\n", rl.rlim_cur);

    // Check if FIFO already exists
    if (access("myfifo", F_OK) == -1) {
        // Create a FIFO (named pipe) if it doesn't exist
        if (mkfifo("myfifo", 0666) == -1) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("FIFO 'myfifo' already exists.\n");
    }

    // Open the pipe for writing
    pipe_fd = open("myfifo", O_WRONLY);
    if (pipe_fd == -1) {
        perror("open");
        return 1;
    }

    // Get the size of the pipe buffer (circular buffer)
    pipe_size = fcntl(pipe_fd, F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
        close(pipe_fd);
        return 1;
    }

    printf("Size of the pipe buffer: %d bytes\n", pipe_size);

    // Close the pipe and remove the FIFO
    close(pipe_fd);
    unlink("myfifo");  // Remove the FIFO after use

    return 0;
}
