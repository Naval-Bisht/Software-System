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
    int ticketNumber;

    // Open the file for reading and writing
    fd = open("17.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Initialize the lock structure for read lock
    lock.l_type = F_RDLCK;    // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;         // Start of the file
    lock.l_len = sizeof(ticketNumber); // Lock the size of an integer
    lock.l_pid = getpid();

    printf("Before entering the read lock\n");
    sleep(2);  // Simulate delay before locking

    // Acquire the read lock (blocking if necessary)
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Inside read lock\n");

   

// Read the current ticket number
    char bfr[100] = {0};
    ssize_t bytesRead = read(fd, bfr, sizeof(bfr) - 1);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }
     ticketNumber = atoi(bfr);  
    printf("Current ticket number: %d\n", ticketNumber);

    printf("Press enter to unlock\n");
    getchar();  // Wait for user input before unlocking

    // Unlock the file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock released\n");

    // Close the file
    close(fd);

    return 0;
}
