/*
============================================================================================
File Name : 3.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Data : 15/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <sys/resource.h>

int main() {
    struct rlimit lmt;

    // Set the lmt for the maximum number of open files
    lmt.rlim_cur = 1024;  // Soft lmt
    lmt.rlim_max = 2048;  // Hard lmt
    setrlimit(RLIMIT_NOFILE, &lmt);
    int a;
    printf(" enter 1 for soft limt and 2 for the hard limit");
    scanf("%d",&a);
    switch (a) {
        case 1:
             printf("Max number of open files set to: %ld\n", lmt.rlim_cur);
            break;
        case 2:
           printf("Max number of open files set to: %ld\n", lmt.rlim_max);
            break;
        default:
            printf("You entered a number other than 1 or 2.\n");
            break;
    }

   
    // 

    return 0;
}

/*
Explanation:
1. setrlimit(RLIMIT_NOFILE, &lmt): Sets the resource lmt for the maximum number of open files.
2. The soft lmt is set to 1024 and the hard lmt is set to 2048.
3. Use man 2 setrlimit to learn more about setting resource limits.
*/