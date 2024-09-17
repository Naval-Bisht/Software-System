/*
============================================================================================
File Name : 7.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 7. Write a simple program to print the created thread ids.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

void* working_thread (void* arg) {
    printf("Thread %ld has ID: %lu\n", (long)arg, pthread_self());
  
    return NULL;
}

int main() {
    pthread_t threads[3];  // Array to hold thread IDs

    // Create three threads
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, working_thread, (void*)i);
    }

    // Join the threads (wait for them to complete)
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
Explanation:
1. pthread_self(): Retrieves the unique ID of the calling thread, which is printed along with the thread number.
2. Similar to the previous exercise, but here we explicitly print the thread IDs.

Alternative Approaches:
- In addition to thread IDs, you can retrieve the process ID using `getpid()` if you are working with processes.
- You could use `gettid()` on Linux to get the kernel thread ID.

For more details, use the following man pages:
- man 3 pthread_self
- man 2 getpid
*/

