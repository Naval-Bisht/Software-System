//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 7 of Hands On List 1 
// 7  Write a program to copy file1 into file2 ($cp file1 file2).
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
// man 2 open 
int main(){ 
       char c1[100];
    char c2[100];

    printf("enter file name to copy\n");
    fgets(c1,100,stdin);

    printf("enter file name where you want to copy\n");
    fgets(c2,100,stdin);
    int rd = open(c1,O_RDWR);
    int wr = write(c2,O_RDWR|O_CREAT,0777);
     if (rd == -1) {
        perror("open error");
        return 1;}

    if (wr==-1){
            perror("write error");
    
        return 1;
    }





 
 
return 0; 
} 
