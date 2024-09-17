/*
============================================================================================
File Name : 6.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 6. Write a simple program to create three threads.
Data : 16/09/2024
============================================================================================
*/
#include <stdio.h> //
#include <stdlib.h> 
#include <pthread.h>//
#include <semaphore.h>

void* working_thread(void* arg) {
    printf("Thread %ld created\n", (long)arg);
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
1. pthread_create(): Creates a new thread. The third argument is the function to be executed by the thread, and the fourth argument is passed to that function.
2. pthread_join(): Waits for the thread to finish. This is essential to ensure that the main program doesn't exit before the threads complete.
3. (void*)i: Casting loop index to void* to pass it as an argument to the thread function.
4. This code demonstrates basic multithreading in C.

Alternative Approaches:
- Instead of `pthread_create()`, you can use `fork()` to create processes. Threads share the same memory space, whereas processes have separate memory spaces.

For more details, use the following man pages:
- man 3 pthread_create
- man 3 pthread_join
*/
