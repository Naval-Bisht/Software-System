/*
============================================================================================
File Name : 20.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Data : 18/09/2024
============================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("my_fifo", 0666);
    int fd = open("my_fifo", O_WRONLY);
    write(fd, "Hello this is fifo file !\n", 29);
    close(fd);
    return 0;
}
/*
Explanation:
1. open("myfifo", O_WRONLY): Opens the FIFO for writing.
2. write(): Writes the message to the FIFO.
3. This program assumes the FIFO has already been created using `mkfifo` or `mknod`.

For more details, use the following man pages:
- man 2 open
- man 2 write
*/
