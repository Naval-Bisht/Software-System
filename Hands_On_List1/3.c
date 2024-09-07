//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 3 of Hands On List 1  
// 3 . Write a program to create a file and print the file descriptor value. Use creat ( ) system call

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

    printf("enter your file name \n");
    char s[100];
    if(fgets(s,sizeof(s),stdin)==NULL){           // check for man fgets (filename , filesize, file stream)
        perror("No file name ");
        return 1;
    }

    

    int x=creat(s,S_IRWXU);   
    s[2]='k';
     int y=creat(s,S_IRWXU);
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

/*

Common Flags for open

    O_RDONLY: Open the file for read-only access.
    O_WRONLY: Open the file for write-only access.
    O_RDWR: Open the file for both reading and writing.
    O_CREAT: Create the file if it does not exist. Requires mode to specify file permissions.
    O_EXCL: Ensure that the file is created only if it does not already exist. It is used with O_CREAT.
    O_TRUNC: Truncate the file to zero length if it already exists. Used with O_WRONLY or O_RDWR.
    O_APPEND: Append data to the end of the file. The file pointer is moved to the end before each write.
    O_NONBLOCK: Open the file in non-blocking mode. For example, when opening a device file, operations that would normally block will return immediately with an error.
    O_SYNC: Write operations will complete according to the requirements of synchronous I/O file integrity completion.
    O_DSYNC: Data modifications will be synchronized with the underlying storage device.

Additional Flags

    O_LARGEFILE: Enable support for large files. This flag allows the opening of files larger than 2 GB on 32-bit systems.
    O_DIRECT: Minimize or eliminate cache effects of I/O operations. Direct I/O can be useful for performance in some scenarios but requires the file to be aligned on a block boundary.

Related System Calls

    close: Closes a file descriptor.

    

                          int close(int fd);

read: Reads data from a file descriptor.



                       ssize_t read(int fd, void *buf, size_t count);

write: Writes data to a file descriptor.



                          ssize_t write(int fd, const void *buf, size_t count);

lseek: Repositions the offset of the file descriptor.



                         off_t lseek(int fd, off_t offset, int whence);

ftruncate: Truncates the file to a specified length.



                           int ftruncate(int fd, off_t length);

fsync: Synchronizes a file’s in-core state with storage device.



                         int fsync(int fd);

fdatasync: Similar to fsync, but only synchronizes the file’s data.



                         int fdatasync(int fd);
*/