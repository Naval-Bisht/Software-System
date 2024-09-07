//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 26 of Hands On List 1 
/*
26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

    int main() {
    // Define the program to execute and the argument to pass

    //insert name as ./program26 if you have created its compiled file in the  previous program

    char s[100];
    char s2[100];

    // Get the executable file name
    printf("Enter the compiled file name: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        perror("No file name entered");
        return 1;
    }

    // Remove the newline character from the file name input
    s[strcspn(s, "\n")] = 0;

    // Get the argument
    printf("Provide the argument: ");
    if (fgets(s2, sizeof(s2), stdin) == NULL) {
        perror("Error in passing argument name");
        return 1;
    }

    // Remove the newline character from the argument input
    s2[strcspn(s2, "\n")] = 0;

    // Create the arguments array for exec
    char *args[] = {s, s2, NULL};

    // Execute the program
    execvp(args[0], args);

    // If execvp returns, there was an error
    perror("execvp failed");
    return 1;
}

 
 