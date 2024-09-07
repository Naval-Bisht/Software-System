//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 14 of Hands On List 1 
/*
14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("This is a Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("This is a Directory\n");
    } else if (S_ISCHR(mode)) {
        printf("This is a  Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("This is a  Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("This is a  FIFO/pipe\n");
    } else if (S_ISLNK(mode)) {
        printf("This is a  Symbolic link\n");
    } else if (S_ISSOCK(mode)) {
        printf("This is a Socket\n");
    } else {
        printf("This is a  Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
      //  fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        perror("Argument error");
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_stat;

    if (stat(file_path, &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    print_file_type(file_stat.st_mode);

    return 0;
}