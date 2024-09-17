/*
============================================================================================
File Name : 2.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Data : 15/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <sys/resource.h>

int main() {


    // Get the limit for the maximum number of open files
        struct rlimit rl;

    getrlimit(RLIMIT_CPU, &rl);
    printf("CPU time limit: soft = %ld, hard = %ld\n", rl.rlim_cur, rl.rlim_max);

    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Open files limit: soft = %ld, hard = %ld\n", rl.rlim_cur, rl.rlim_max);

   

    return 0;
}

/*
Explanation:

 Use man 2 getrlimit to learn more about the getrlimit system call.
 The soft and hard limits for CPU time are both -1, 
 which means that there is no limit imposed on CPU time usage for the process. A value of -1 in resource limits signifies that the resource is unlimited
*/

