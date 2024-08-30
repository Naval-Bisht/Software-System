//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 11 of Hands On List 1 
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
/*
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.

 use fcntl
*/
int main() {
    int fd = open("11b.txt", O_RDWR |O_CREAT| O_APPEND,0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor using fcntl
    int k = fcntl(fd, F_DUPFD, 0);
    if (k < 0) {
        perror("fcntl");
        return 1;
    }

    // Append data using the original descriptor
    write(fd, "Original FD (fcntl)\n", 21);

    // Append data using the duplicated descriptor
    write(k, "Duplicated FD (fcntl)\n", 23);

    close(fd);
    close(k);

    return 0;
}
