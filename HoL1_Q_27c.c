//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 27 of Hands On List 1 
/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <sched.h>

//  execv

int main(){ 
       char *args[] = {"ls", "-Rl", NULL};
    execv("/bin/ls", args);
    perror("error in executing the  execv");
    return 1;
  
 
return 0; 
} 

