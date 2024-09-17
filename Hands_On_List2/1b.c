/*
============================================================================================
File Name : 1b.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
                a. ITIMER_REAL
                b. ITIMER_VIRTUAL
                c. ITIMER_PROF
Data : 15/09/2024
============================================================================================
*/



/*
 * Program to set an interval timer using ITIMER_PROF (profiling).
 * This timer sends a SIGPROF signal when it expires. It decrements both during process execution and when the system is executing on behalf of the process.
 * You can read more about setitimer() and ITIMER_PROF by using: `man 2 setitimer`
 */
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Profiling Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1); 

    return 0;
}


/*
 * Alternative Approaches:
 * - `sigaction()` can replace `signal()` for handling signals.
 * - This timer decrements during both process execution and system calls, making it suitable for profiling.
 */

