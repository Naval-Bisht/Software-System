//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 28 of Hands On List 1 
// 28. Write a program to get maximum and minimum real time priority.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <sched.h>

int main() {
    int mxp = sched_get_priority_max(SCHED_FIFO);
    int mnp = sched_get_priority_min(SCHED_FIFO);

    if (mxp  == -1 || mnp == -1) {
        perror("error in executing the  sched_get_priority");
        return 1;
    }

    printf("Max real-time priority: %d\n", mxp);
    printf("Min real-time priority: %d\n", mnp);

    return 0;
} 
