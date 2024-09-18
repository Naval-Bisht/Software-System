/*
============================================================================================
File Name : 14.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe 
                            and display on
the monitor.
Data : 18/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefds[2]; // Array to hold the pipe's file descriptors
   
    // Create the pipe
    if (pipe(pipefds) == -1) {
        perror("pipe");
        return 1;
    }
     char wm[] = "Hello naval here ";
    char rm[100];
    
    
    // Write to the pipe
    write(pipefds[1], wm, strlen(wm) + 1); // +1 for null terminator

    // Read from the pipe
    read(pipefds[0], rm, sizeof(rm));

    // Display the message read from the pipe
    printf("Read from pipe: %s\n", rm);
    
    // Close the pipe file descriptors
    close(pipefds[0]); // Close the read end
    close(pipefds[1]); // Close the write end
    
    return 0;
}

/*
Explanation:

For more details, use the following man pages:
- man 2 pipe
- man 2 fork
- man 3 popen
*/
