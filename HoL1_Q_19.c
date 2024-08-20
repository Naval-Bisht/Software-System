//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 19 of Hands On List 1 
//19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>    // it is used to take time counter


void rdtscl(unsigned long long *ll)
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));                        
    *ll = ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );           
}


int main(){ 
 unsigned long long s, e;
rdtscl(&s);

 int k= getpid();
 printf("%d\n",k);
rdtscl(&e);
printf("time taken=%llu ticks\n",e-s);

 
return 0; 
} 




// i used to find the time by this method but the time we get is same as time in microsend and it dit it in that same microsecods 


//    useconds_t s;
//  printf("%u\n",s);
//  printf("%d\n",k);

//    useconds_t s2;
//  printf("%u\n",s2);

//  printf("%u\n",s2-s);








// we can also use 


/////////////////////////////////////////////////

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC, &start);

    // pid_t pid = getpid();

    // clock_gettime(CLOCK_MONOTONIC, &end);

    // long seconds = end.tv_sec - start.tv_sec;
    // long nanoseconds = end.tv_nsec - start.tv_nsec;
    // double elapsed = seconds + nanoseconds*1e-9;



    



//     The basic idea is to determine how long each tick lasts (in nanoseconds) and multiply the number of ticks by that duration.
// General Formula ==> time = (ticks/frequency in Hz)* 10^9

// The conversion formula is:
// time in nanoseconds=ticksfrequency in Hz×109
// time in nanoseconds=frequency in Hzticks​×109

// Here:

//     ticks is the number of cycles or ticks that you want to convert.
//     frequency in Hz is the clock frequency of the system (in hertz, cycles per second).
//     109109 is the number of nanoseconds in one second (1 second = 109109 nanoseconds).

// Step-by-Step Conversion

//     Determine the Frequency: Find the clock frequency of your timer source. For example:
//         If you're using the CPU's Time Stamp Counter (TSC), this would be the CPU clock frequency (e.g., 3 GHz = 3,000,000,000 Hz).
//         If you're using the High Precision Event Timer (HPET), this might be a fixed frequency like 14.31818 MHz (14,318,180 Hz).

//     Calculate the Duration of Each Tick: The duration of each tick is the reciprocal of the frequency in seconds.
//     duration of each tick=1frequency
//     duration of each tick=frequency1​

//     To get this duration in nanoseconds, multiply by 109109:
//     duration of each tick in nanoseconds=109frequency in Hz
//     duration of each tick in nanoseconds=frequency in Hz109​

//     Convert Ticks to Nanoseconds: Multiply the number of ticks by the duration of each tick in nanoseconds.
//     time in nanoseconds=ticks×109frequency in Hz
//     time in nanoseconds=ticks×frequency in Hz109​

// Example Calculation

// Let's say you have 5,000,000 ticks, and your CPU runs at 3 GHz (3,000,000,000 Hz):

//     Determine the Duration of Each Tick:
//     duration of each tick=109 nanoseconds3,000,000,000 Hz=0.3333 nanoseconds per tick
//     duration of each tick=3,000,000,000 Hz109 nanoseconds​=0.3333 nanoseconds per tick

//     Convert Ticks to Nanoseconds:
//     time in nanoseconds=5,000,000×0.3333=1,666,500 nanoseconds=1.6665 milliseconds
//     time in nanoseconds=5,000,000×0.3333=1,666,500 nanoseconds

// #include <stdint.h>
// #include <stdio.h>

// uint64_t ticks_to_nanoseconds(uint64_t ticks, uint64_t frequency_hz) {
//     return (ticks * 1000000000ULL) / frequency_hz;
// }

// int main() {
//     uint64_t ticks = 5000000; // Example tick count
//     uint64_t frequency_hz = 3000000000; // 3 GHz

//     uint64_t nanoseconds = ticks_to_nanoseconds(ticks, frequency_hz);
//     printf("Time: %llu nanoseconds\n", nanoseconds);

//     return 0;
// }