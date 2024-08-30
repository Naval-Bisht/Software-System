//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 8 of Hands On List 1 
//8. Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int fd = open("8.txt", O_RDONLY);
     char bfr[100];
    ssize_t mxs;
    int k=0;
    int line=1;
    while ((mxs = read(fd, bfr, 100)) > 0) {
        for(int i=0;i<mxs;i++){

              if (bfr[i]== '\n') {
                // calculate the lenght from which index to which we have to read
                int len = i-k+1;
                // now print the line with line no 
                // and print the string using char[] by defining the line size
                // for 1st it will run from 0 to the first new line character' \n'
                // then it increament the i index from 0 to j+1 for next line and so on
                printf("%d : %.*s\n",line++,len,bfr+k);
                char ch;
                ch = getchar();
                // incrementing the i index to start of new linel
                k=i+1;

              }
             k=0;                  // when the buffer size ended we want to again point to the start of new buffer 
        }
       
    }

    if (mxs== -1) {
        perror("Read  error occured");
    }
    close(fd);
   
return 0; 
} 
