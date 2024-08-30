//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 24 of Hands On List 1 
//24. Write a program to create an orphan process.
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
     int g = getpid();
    int pid = fork();
if(pid<0){
    perror("error in fork ");
    return 1;
    
}
 else if(pid==0){
    sleep(2);
    int k= getppid();
    if(g==k){
        printf("I have parent with pid as %d and child have pid as %d  \n",k,getpid());
    }
    else{
             printf("I am a orphan process having %d as pid and pid %d as systemd as my grandparent  \n ",getpid(),getppid());
             exit(0);
    }

 }
 else{
    printf("I am parent process of pid as %d \n",getpid());
    // comment wait for orphan
   //wait(NULL);            // commetn this to check for orphan process and please save first
 }

 
 
return 0; 
} 
