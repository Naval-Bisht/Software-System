//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 4 of Hands On List 1 
//  4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
/*
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
    // man creat  // to know about how to open and close the file
    // create a file with program  

     printf("enter your file name \n");
    char s[100];
    if(fgets(s,sizeof(s),stdin)==NULL){           // check for man fgets (filename , filesize, file stream)
        perror("No file name ");
        return 1;
    }

    int x = open(s, O_RDWR | O_CREAT | O_EXCL, 0777);

    if (x == -1) {
    // Function failed, check errno
     printf("Error opening file: %d\n", errno);  // error no give the no of last error
        printf("Error description: %s\n", strerror(errno));   // discription of the error no 

    }

    printf("File opened successfully with file descriptor: %d\n", x);
    close(x);

return 0; 
} 


////////////////////////////
/* types of error 

 $ errno -l
           EPERM 1 Operation not permitted
           ENOENT 2 No such file or directory
           ESRCH 3 No such process
           EINTR 4 Interrupted system call
           EIO 5 Input/output error
           ...


*/

// Closing a file descriptor (FD) is an important part of file management 
// in Unix-like operating systems. Here’s why it’s crucial to close an FD:
// 1. Resource Management
//     System Resources: File descriptors are finite resources managed by the 
//     operating system. Each open file consumes a file descriptor, and there is a 
//     limit to how many file descriptors a process or the entire system can have 
//     open at any one time. By closing a file descriptor when it’s no longer 
//     needed, you release that resource back to the system for reuse.
//     Avoiding Leaks: Failing to close file descriptors leads to resource leaks,
//      where file descriptors remain allocated even if the file is no longer needed. 
//      Over time, this can exhaust the available file descriptors, leading to errors 
//      such as EMFILE (too many open files) or ENFILE (file table overflow).
// 2. Ensuring Data Integrity
//     Flushing Buffers: When writing to files, data might be buffered in memory 
//     before being physically written to disk. Closing a file descriptor ensures that
//      all buffered data is flushed and properly written to the file. If you don’t 
//      close the FD, data might remain in the buffer and could be lost if the program 
//      crashes or terminates unexpectedly.
// 3. Releasing Locks
//     File Locks: If your program or another process has set file locks, closing 
//     the file descriptor can release those locks. This ensures that other processes 
//     or threads can access the file if necessary.
// 4. Clean Up
//     Good Practice: Properly closing file descriptors is a good programming 
//     practice. It helps prevent issues and makes your code more predictable and maintainable.
//      It also adheres to the principle of resource management, ensuring that resources 
//      are allocated and deallocated properly.