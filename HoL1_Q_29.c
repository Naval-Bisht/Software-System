//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 29 of Hands On List 1 
/*
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <sched.h>
int main(){ 
    int pid = getpid();
    int sdl = sched_getscheduler(pid);

    if (sdl == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: %d\n", sdl);

    struct sched_param p;
    p.sched_priority = 1;

    if (sched_setscheduler(pid, SCHED_FIFO, &p) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO.\n");
    return 0;
 
return 0; 
} 
