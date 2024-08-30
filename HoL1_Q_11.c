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
a. use dup

*/

int main() {
   char c1[1000];

    printf("enter file name \n");
    fgets(c1,1000,stdin); 
    int fd = open(c1, O_RDWR |O_APPEND| O_CREAT, 0644);
    if (fd < 0) {
        perror("open error");
        return 1;
    }

    // Duplicate the file descriptor using dup
    int k = dup(fd);
    if (k < 0) {
        perror("dup");
        return 1;
    }

    // Append data using the original descriptor
    write(fd, "Original FD\n", 12);

    // Append data using the duplicated descriptor
    write(k, "Duplicated FD\n", 14);

    close(fd);
    close(k);

    return 0;
}
