//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 16 of Hands On List 1 
/*
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
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
    struct flock lock;
    int a;
    
    int fd;
    fd = open("16.txt",O_RDWR|O_CREAT,0666);
    lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid=getpid();
    printf("before enterig the read lock\n");
    sleep(2); 

    fcntl(fd, F_SETLK, &lock);   //F_SETLKW is not used in read because it will 
                                 // not make other file to aquire the lock but iin read we can have multiple read lock

    printf("inside read \n");

    printf("press enter to unlock\n");

    getchar();

     lock.l_type = F_UNLCK;
     printf("read unlocked\n");
     fcntl(fd, F_SETLK, &lock);

     close(fd);



 
 
return 0; 
} 
