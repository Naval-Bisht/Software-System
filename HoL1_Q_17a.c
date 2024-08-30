//  Rollno: MT2024099 
//  Name : Naval Kihsore Singh Bisht 
//  Question No 17 of Hands On List 1 
/*
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
// write ticket
int main() {
    struct flock lock;
    int fd;

    // Open the file for reading and writing, create it if it doesn't exist
    fd = open("17.txt", O_RDWR | O_CREAT, 0666);
   
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;        
    lock.l_len = 0;          
    lock.l_pid = getpid();
    printf("Before entering the write lock\n");
    sleep(2); 

    fcntl(fd, F_SETLKW, &lock);
      

    printf("Inside write lock\n");

    // Read the current ticket number
    char bfr[100] = {0};
    ssize_t bytesRead = read(fd, bfr, sizeof(bfr) - 1);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

   
    int tno = atoi(bfr);  
    tno += 1;             

    snprintf(bfr, sizeof(bfr), "%d\n", tno); // back t0 string 

    // Reset the file offset to the beginning before writing
    lseek(fd, 0, SEEK_SET);

    // Write the new ticket number back to the file
    ssize_t bytesWritten = write(fd, bfr, strlen(bfr));
    
    printf("New ticket number: %d\n ", tno);

    printf("Press enter to unlock\n");
    getchar(); 

    
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
     

    printf("Write lock released\n");

    // Close the file
    close(fd);

    return 0;
}
