//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 5 of Hands On List 1 
/*5. Write a program to create five new files with infinite loop. Execute the program in the background
         and check the file descriptor table at /proc/pid/fd. */
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
int main(){ 
    int i=1;
    while(1)
   {
        if(i<=5&&i>0){
             char ch[20];
         sprintf(ch, "%d.txt", i);
        int x = creat(ch,0666); 
           if (x == -1) {
            perror("creat");
            return 1;
             }
        
        close(x);

        }
        i++;
       
         }  
 
return 0; 
} 

         // to run in bacggroud  first compiler the file 
         // theen reun using ./a.out &    ==> it will givve the pid of the runnign process and you can also run the terminal
         //let the pid we get is 11361
         // ls /proc  ==> to check all the pid of the running process 
         // ls /proc/11361/fd  to check the process files
         // Each number corresponds to a different file descriptor:

//     0 typically represents standard input (stdin).
//     1 typically represents standard output (stdout).
//     2 typically represents standard error (stderr).
//     Higher numbers represent other files, sockets, or resources that the process has opened.

// to check all the deatail about the process 
//  cat /proc/11361/status  ==> run this line

// to stop the process   ==>                kill 11361
