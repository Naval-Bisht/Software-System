//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 15 of Hands On List 1 
/*15. Write a program to display the environmental variable of the user (use environ).*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
extern char **environ;

int main() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
