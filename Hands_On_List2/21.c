/*
============================================================================================
File Name : 21.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Data : 19/09/2024
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO1 "/tmp/fifo1"  // First FIFO for communication
#define FIFO2 "/tmp/fifo2"  // Second FIFO for communication

int main() {
    char buffer[100];
    int fd1, fd2;

    // Create both FIFOs
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    while (1) {
        // Write to FIFO1 and read from FIFO2

        // Open FIFO1 for writing
        fd1 = open(FIFO1, O_WRONLY);
        printf("Program 1: Enter message: ");
        fgets(buffer, 100, stdin);
        write(fd1, buffer, strlen(buffer) + 1);  // Write message to FIFO1
        close(fd1);

        // Open FIFO2 for reading
        fd2 = open(FIFO2, O_RDONLY);
        read(fd2, buffer, sizeof(buffer));       // Read response from FIFO2
        printf("Message received from program 2 is : %s\n", buffer);
        close(fd2);
    }

    return 0;
}
