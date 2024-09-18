/*
============================================================================================
File Name : 20a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Data : 18/09/2024
============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int fd = open("my_fifo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s", buffer);
    close(fd);
    return 0;
}
/*
Explanation:
1. open("myfifo", O_RDONLY): Opens the FIFO for reading.
2. read(): Reads the data from the FIFO into the buffer.
3. This program assumes the FIFO has already been created using `mkfifo` or `mknod`.

For more details, use the following man pages:
- man 2 open
- man 2 read
*/
