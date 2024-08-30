#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    struct flock lock;
    int fd;

    // Open the file for reading and writing, create it if it doesn't exist
    fd = open("17.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Initialize the lock structure
    lock.l_type = F_WRLCK;    // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;         // Start of the file
    lock.l_len = 0;           // Lock the entire file
    lock.l_pid = getpid();

    printf("Before entering the write lock\n");
    sleep(2);  // Simulate delay before locking

    // Acquire the write lock (blocking if necessary)
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Inside write lock\n");

    // Read the current ticket number
    int ticketNumber = 0;
    ssize_t bytesRead = read(fd, &ticketNumber, sizeof(ticketNumber));
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // If the file is empty, initialize ticketNumber to 0
    if (bytesRead == 0) {
        ticketNumber = 0;
    }

    // Increment the ticket number
    ticketNumber++;

    // Reset the file offset to the beginning before writing
    lseek(fd, 0, SEEK_SET);

    // Write the new ticket number back to the file
    ssize_t bytesWritten = write(fd, &ticketNumber, sizeof(ticketNumber));
    if (bytesWritten == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("New ticket number: %d\n", ticketNumber);

    printf("Press enter to unlock\n");
    getchar();  // Wait for user input before unlocking

    // Unlock the file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock released\n");

    // Close the file
    close(fd);

    return 0;
}
