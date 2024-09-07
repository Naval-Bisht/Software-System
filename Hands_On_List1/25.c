//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 25 of Hands On List 1 
//  25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
/*
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
/*
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/
int main(){ 
    int  pids[3];
    int i;

    for (i = 0; i < 3; i++) {
        pids[i] = fork();

        if (pids[i] == -1) {
            perror("fork error for child ");
            return 1;
        }

        if (pids[i] == 0) {
            // Child process
            printf("Child %d (PID: %d) executing.\n", i, getpid());
            sleep(2);  // for checking that it is havig a wait so that we can check our observation
            exit(0);
        }
    }

    // Parent process waits for the second child (index 1)
    waitpid(pids[1], NULL, 0);
    printf("Parent waited for child %d PID: %d.\n", 1, pids[1]);

    // Wait for the remaining children
    while (wait(NULL) > 0);

 
 
return 0; 
} 
