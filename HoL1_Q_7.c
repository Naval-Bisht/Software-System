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
       char c1[1000];
    char c2[1000];

    printf("enter file name to copy\n");
    fgets(c1,1000,stdin);                                     // name of file from where you want the data to be copied 

    printf("enter file name where you want to copy\n");
    fgets(c2,1000,stdin);                                    // name of file where data will be copied 
    int rd = open(c1,O_RDWR);                              // opening a file to read the the data 
    int rd2 = open(c2,O_RDWR|O_CREAT,0777);                // opening the file where data will be coped 
    


     if (rd == -1) {
        perror("open file error");
        return 1;}

    if (rd2==-1){
            perror("write file error");
    
        return 1;
    }


     char ch[1000];
    ssize_t x;                                          // bytes size that will be used for the read . it stores the values of bytes which will be used 
    while ((x = read(rd, ch, 1000)) > 0) {
        printf("%ld\n",x);
        if (write(rd2, ch, x) != x) {            
            perror("write is not able to happen ");
            close(rd);
            close(rd2);
            return 1;
        }
    }
    if (x == -1) {
        perror("read not done");
    }
    close(rd);
    close(rd2);
    
 
return 0; 
} 
