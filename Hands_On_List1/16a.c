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
    fd = open("16.txt",O_RDWR|O_APPEND|O_CREAT,0666);
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid=getpid();
    printf("before enterig the write lock\n");
    sleep(2); 

    fcntl(fd, F_SETLKW, &lock);   //F_SETLKW is not used in read because it will 
                                 // not make other file to aquire the lock but iin read we can have multiple read lock

    printf("inside write \n");
    char *c2 = strdup("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean\n");

    if (write(fd, c2, strlen(c2) + 1) == -1) {
        perror("write error ");
        close(fd);
        return 1;
    }
    

    printf("press enter to unlock\n");

    getchar();

     lock.l_type = F_UNLCK;
     printf("write unlocked");
     fcntl(fd, F_SETLKW, &lock);
close(fd);


 
 
return 0; 
} 
