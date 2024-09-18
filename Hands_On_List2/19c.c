/*
============================================================================================
File Name : 19c.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 19. Create a FIFO file by
                    a. mknod command
                    b. mkfifo command
                    c. use strace command to find out, which command (mknod or mkfifo) is better.
                    d. mknod system call
                    e. mkfifo library function
Data : 18/09/2024
============================================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *fifo_path = "fifo_file";

    // Create a FIFO file using mknod system call
    if (mknod(fifo_path, __S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file '%s' created successfully using mknod.\n", fifo_path);
    return 0;
}
