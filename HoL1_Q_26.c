//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 26 of Hands On List 1 
/*
26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

// program  created for which we check that is executed by the second program
// run this program first and make a exucutable file for this code 

// make a complie file for this file and remane that folder so that it can be used further

// it is done by-->   cc -o program26 HoL1_Q_26.c
//to run this --> ./program26 naval
// naval is the argument name you passed


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please insert more argument in the compile time in %s as %s <argument>\n", argv[0],argv[0]);
        return 1;
    }
    
    printf("Hello, %s!\n", argv[1]);
    return 0;
}

