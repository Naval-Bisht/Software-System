/*
============================================================================================
File Name : 22.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds,
                     use select system call with FIFO.
Data : 19/09/2024
============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include<sys/stat.h>

int main() {
    int fd;
    char buffer[128];
    fd_set readfds;
    struct timeval timeout;

    // Create and open FIFO for reading
    mkfifo("myfifo22", 0666);
    fd = open("myfifo22", O_RDONLY | O_NONBLOCK);

    // Set up timeout for 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Initialize the file descriptor set
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    // Wait for data to be available
    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        return 1;
    } else if (ret == 0) {
        printf("Timeout: No data written to FIFO within 10 seconds.\n");
    } else {
        read(fd, buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
    }

    close(fd);
    return 0;
}

/*
 echo "Hello from another terminal!" > myfifo  // type this in new terminal too see the data 

Explanation:
1. `select()` is used to wait for data on the FIFO with a timeout of 10 seconds.
2. If data is available, `select()` returns a positive value, and the program reads the data.
3. If the timeout occurs, the program prints a timeout message.
4. The FIFO is created using `mkfifo()`.

For more details, use the following man pages:
- man 2 select
- man 2 mkfifo
- man 2 read
*/
