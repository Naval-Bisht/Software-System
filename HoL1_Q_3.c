//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 3 of Hands On List 1  
// 3 . Write a program to create a file and print the file descriptor value. Use creat ( ) system call
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main(){ 

    printf("enter your file name \n");
    char s[100];
    if(fgets(s,sizeof(s),stdin)==NULL){           // check for man fgets (filename , filesize, file stream)
        perror("No file name ");
        return 1;
    }

    int x=creat(s,S_IRUSR);
    s[2]='k';
     int y=creat(s,S_IRUSR);
    if (x < 0) {
        perror("creat is not created succesully \n");
        return 1;
    }

    printf("File descriptor: %d\n ", x);

     if (y < 0) {
        perror("creat is not created succesully \n");
        return 1;
    }
    printf("File descriptor: %d\n ", y);
    close(y);

    close(x);

    // to check this the file created have different discroptor values 


 
return 0; 
} 



// to check type $man creat

//   The table below shows the section numbers of the manual followed  by  the  types  of
//        pages they contain.

//        1   Executable programs or shell commands
//        2   System calls (functions provided by the kernel)
//        3   Library calls (functions within program libraries)
//        4   Special files (usually found in /dev)
//        5   File formats and conventions, e.g. /etc/passwd
//        6   Games
//        7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7),
//            man-pages(7)
//        8   System administration commands (usually only for root)
//        9   Kernel routines [Non standard]

//        A manual page consists of several sections.