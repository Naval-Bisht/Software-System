//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 10 of Hands On List 1 
/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
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
    fgets(c1,1000,stdin); 
   
     int fd = open(c1, O_RDWR |O_TRUNC| O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    char c1[20];

    printf("enter file name to copy\n");
    fgets(c1,20,stdin);  
    if (write(fd, c1, sizeof(c1)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }
    int k= lseek(fd, 10, SEEK_SET);
    if ( k == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }
     char c2[10];

    printf("enter file name to copy\n");
    fgets(c2,10,stdin);  

    if (write(fd, c2, sizeof(c2)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }
    close(fd);
    printf("the value of lseek is %d\n",k);
    return 0;
 
 
return 0; 
} 
