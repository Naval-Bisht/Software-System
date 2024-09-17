/*
============================================================================================
File Name : 5.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 5. Write a program to print the system limitation of
                    a. maximum length of the arguments to the exec family of functions.
                    b. maximum number of simultaneous process per user id.
                    c. number of clock ticks (jiffy) per second.
                    d. maximum number of open files
                    e. size of a page
                    f. total number of pages in the physical memory
                    g. number of currently available pages in the physical memory.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
     printf("Max argument length: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Max processes per user: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE));
    printf("Total pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Available pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));

}

/*
Explanation:
1. sysconf(_SC_ARG_MAX): Retrieves the maximum length of arguments to the exec family of functions.
2. sysconf(_SC_CHILD_MAX): Retrieves the maximum number of processes per user ID.
3. sysconf(_SC_CLK_TCK): Retrieves the number of clock ticks (jiffies) per second, used in timing-related system functions.
4. sysconf(_SC_OPEN_MAX): Retrieves the maximum number of files that can be opened by a process.
5. sysconf(_SC_PAGESIZE): Retrieves the size of a page in bytes, which is important for memory allocation and management.
6. sysconf(_SC_PHYS_PAGES): Retrieves the total number of pages in the physical memory, which can be used to estimate total memory size.
7. sysconf(_SC_AVPHYS_PAGES): Retrieves the number of currently available pages in physical memory.

Alternative Approaches:
- Instead of using `sysconf()`, you could read these values from the `/proc` filesystem in Linux (e.g., `/proc/meminfo` for memory info).
- Use the `getrlimit()` system call for some of the resource limits, like the maximum number of open files.

For more details, use the following man pages:
- man 2 sysconf
- man 5 proc (for reading from `/proc`)
*/
