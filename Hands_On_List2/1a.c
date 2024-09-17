/*
============================================================================================
File Name : 1a.c
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
 * Program to set an interval timer using ITIMER_VIRTUAL (process virtual time).
 * This timer sends a SIGVTALRM signal when it expires. It decrements only when the process is executing.
 * You can read more about setitimer() and ITIMER_VIRTUAL by using: `man 2 setitimer`
 */
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Virtual Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1); 

    return 0;
}


/*
 * Alternative Approaches:
 * - You can also use `sigaction()` here for better signal handling.
 * - This timer only decreases while the process is executing, so it won't decrement during sleep or I/O wait.
 */

