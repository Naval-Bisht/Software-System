/*
============================================================================================
File Name : 4.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 4. Write a program to measure how much time is taken to execute 100 getppid ( )
                  system call. Use time stamp counter.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <x86intrin.h>  // For __rdtsc()
#include <unistd.h> 
int main() {
    unsigned long long start, end;
    start = __rdtsc();  // Get the starting time using the time stamp counter

    for (int i = 0; i < 100; i++) {
        getppid();  // Make 100 getppid() system calls
    }

    end = __rdtsc();  // Get the ending time
    printf("Time taken for 100 getppid() calls: %llu CPU cycles\n", end - start);

    return 0;
}

/*
Explanation:
1. __rdtsc(): Reads the time stamp counter, which provides the number of CPU cycles since the last reset.
2. We measure the time taken to execute 100 getppid() system calls.
3. Use man 2 getppid to learn more about the getppid system call.
4. This code requires the x86intrin.h header for the __rdtsc intrinsic.
*/