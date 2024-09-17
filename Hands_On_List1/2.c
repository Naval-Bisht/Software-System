//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 2 of Hands On List 1 
/*
2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
int main(){ 
    int a;
    a=10;
    while (1)
    {
        /* code */ 
        //  infinte loop
    }
    
    
 
 
return 0; 
} 


   // to run in bacggroud  first compiler the file 
         // theen reun using ./a.out &    ==> it will givve the pid of the runnign process and you can also run the terminal
         //let the pid we get is 11361
         // ls /proc  ==> to check all the pid of the running process 
         // ls /proc/11361/fd  to check the process files
         // Each number corresponds to a different file descriptor:
        // ls -l /proc/11361/fd all thde detauis about the descriptor
        

// to check all the deatail about the process 
//  cat /proc/11361/status  ==> run this line

// to stop the process   ==>                kill 11361

