/*
============================================================================================
File Name : 19d.c
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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "fifo_file";

    // Create a FIFO file using mkfifo library function
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file '%s' created successfully using mkfifo.\n", fifo_path);
    return 0;
}
