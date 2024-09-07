//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 17 of Hands On List 1 
/*
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
// read ticket
int main() {
    struct flock lock;
    int fd;
    int tno;
    fd = open("17.txt", O_RDWR | O_CREAT, 0666);  
    lock.l_type = F_RDLCK;    
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;       
    lock.l_len = sizeof(tno);
        lock.l_pid = getpid();

    printf("Before entering the read lock\n");
    sleep(2);

    // Acquire the read lock (blocking if necessary)
    fcntl(fd, F_SETLKW, &lock);
     

    printf("Inside read lock\n");
// Read the current ticket number
    char bfr[100] = {0};
    ssize_t bytesRead = read(fd, bfr, sizeof(bfr) - 1);
     tno = atoi(bfr);  
    printf("Current ticket number: %d \n", tno);

    printf("Press enter to unlock\n");
    getchar();  
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
      

    printf("Read lock released\n");

    // Close the file
    close(fd);

    return 0;
}
