//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 6 of Hands On List 1 
//  6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
#include<stdio.h>  
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char ch[100];
    ssize_t in = read(0, ch, 100);                
    if (in == -1) {
        perror("unsuccesful read");
            return 1;    // returnning 1 because in terminal on using $? commad
                        // we can also check program is executed succesfully or not
    }

    printf(" succesfully read the string entered \n\n");
     ch[in] = '\0';  // after if string enteres is small it will give garbage value
                      // in the end to remove the garbadge valeu

    // Write to STDOUT
    ssize_t out = write(0, ch, in );  // you can give size 100 or you can give 
                                                    // by writing input-->(in) it wil not print garbage value as we created it 
                                                    // as string by givig the null character
                                                    
    if (out == -1) {
        perror("write uncessuful");
        return 1;
    }
     printf(" succesfully write  the string entered \n\n");



    return 0;
}


   // man 2 read

      // ssize_t read(int fd, void buf[.count], size_t count);
// first parameter is start, second parameter is file name --> (ch) where data is stoed, third parameted is the sixe of file stored 
// in place of first parameter we can use STDIN_FILENO it is  preferred for readability and to make it clear that the file descriptor being used is for standard input.
// in palce of third parameter we can also use --> ( sizeof(ch) - 1  )


// man 2 write

//   ssize_t write(int fd, const void buf[.count], size_t count);
