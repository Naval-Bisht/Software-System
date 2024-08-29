//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 1 of Hands On List 1 
/*
1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
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
    char c1[100];

    printf("enter file name \n");
    fgets(c1,100,stdin); 
     int fd = open(c1, O_RDWR |O_TRUNC| O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    close(fd);
   
      int result = mkfifo("my_fifo", 0666);
    if (result == 0) {
        printf("FIFO created successfully.\n");
    } else {
        perror("mkfifo");
    }
    return 0;

} 




// to compile just give cc filenaeme
//                 the check by ./a.out

//or if want a to give the name to output file 
            // cc filemnme -o XYZ
            // ./XYZ