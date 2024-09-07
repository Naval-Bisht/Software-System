//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 12 of Hands On List 1 
//12. Write a program to find out the opening mode of a file. Use fcntl.
/*
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>


int main() {
    char c1[1000];

    printf("enter file name \n");
    fgets(c1,1000,stdin); 
    int fd = open(c1, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }
    int accmode = flags & O_ACCMODE;
    if (accmode == O_RDONLY) {
        printf("Read-only mode.\n");
    } else if (accmode == O_WRONLY) {
        printf("Write-only mode.\n");
    } else if (accmode == O_RDWR) {
        printf("Read-write mode.\n");
    }
    close(fd);
    return 0;
}

