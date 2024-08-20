//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 21 of Hands On List 1 
// 21. Write a program, call fork and print the parent and child process id.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>   // it is used to create wait 
int main(){ 

    int pid;
  int status;

  if ((pid = fork()) < 0){
             perror("fork  error");
             return 1;
      }
   
  else if (pid == 0) {
    puts("Child's Process ");
    int l = getpid();
    int m= getppid();
    printf("Child's pid is %d and my parent's is %d\n", l,m);
  }
  else {
    puts("Parent's process ");
    int l = getpid();
    
      printf("Parent's pid is %d and my child's is %d\n", l, pid);
          wait(NULL);                  // thsi command is used to wait the parent till the chid compelte 
  }

 
return 0; 
} 

// $pidof systemd
// this command is used to find the pid of systemd 
// if we do not write wait(NULL) this will lead to end of paerent and the child will became orphan and when we request for 
   // its paeretn pid it will return the pid of grandpareetn that is systemd becsuse it is the paretn of all the pocess runnig 





// pid_t is a data type used in Unix-like operating systems to represent process IDs (PIDs). 
//It is defined in the <sys/types.h>