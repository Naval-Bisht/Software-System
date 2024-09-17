//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 23 of Hands On List 1
// 23. Write a program to create a Zombie state of the running program. 
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

int main(){ 
     int pid = fork();

    if (pid == -1) {
        perror("error in fork \n");
        return 1;
    }

    else if (pid == 0) {
        printf("Child process PID: as  %d .\n", getpid());
      //  printf("Child  parenet process PID: as  %d .\n", getppid());
        exit(0);
    } else {
        // Parent  sleeps, child becomes a zombie as it has no whaere to go 
        sleep(5);

         printf("Parent  process PID:as  %d .\n", getpid());
       // wait(NULL);  // Reap the zombie process
    }

 
 
return 0; 
} 


// Sleep for 5 seconds to check the zombie state in terminal 
        // run this process FG or BG use below command to check zombie process
        // $ps aux | grep Z
        // here parent is sleeping for 5 sec without calling wait()
        // so child become zombie because it is exited but still not yet acknowledged by parent