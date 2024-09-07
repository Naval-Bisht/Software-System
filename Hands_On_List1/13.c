//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 13 of Hands On List 1 
/*
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/select.h>
int main(){ 

    fd_set rd;
    FD_ZERO(&rd);
    FD_SET(STDIN_FILENO, &rd);
    struct timeval tmout;
    tmout.tv_sec = 10;
    tmout.tv_usec = 0;
    int result = select(STDIN_FILENO + 1, &rd, NULL, NULL, &tmout);
    if (result == -1) {
        perror("select");
        return 1;
    } else if (result == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        printf("Data is available.\n");
    }
    return 0;

} 
