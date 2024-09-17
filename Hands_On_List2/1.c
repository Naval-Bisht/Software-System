/*
============================================================================================
File Name : 1.c
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
 * Program to set an interval timer using ITIMER_REAL (real-time clock).
 * This timer sends a SIGALRM signal when it expires. It decrements in real-time.
 * You can read more about setitimer() and ITIMER_REAL by using: `man 2 setitimer`
 */

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, timer_handler);

    timer.it_value.tv_sec = 10;         // Initial 10 seconds
    timer.it_value.tv_usec = 10;        // 10 microseconds
    timer.it_interval.tv_sec = 10;      // Subsequent intervals of 10 seconds
    timer.it_interval.tv_usec = 10;     // 10 microseconds

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1); // Loop indefinitely to allow timer to trigger

    return 0;
}


/*
 * Alternative Approaches:
 * - Instead of using `signal()`, you can use `sigaction()` for more robust signal handling.
 * - Modify the interval to test different timings, e.g., try 5 seconds or different microsecond values.
 */
