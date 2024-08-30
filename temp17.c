#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
// write ticket
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
    char bfr[100] = {0};
    ssize_t bytesRead = read(fd, bfr, sizeof(bfr) - 1);
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Convert the buffer to an integer, increment the ticket number
    int ticketNumber = atoi(bfr);  // Convert string to integer
    ticketNumber += 1;             // Increment ticket number

    // Convert the incremented ticket number back to string
    snprintf(bfr, sizeof(bfr), "%d\n", ticketNumber);

    // Reset the file offset to the beginning before writing
    lseek(fd, 0, SEEK_SET);

    // Write the new ticket number back to the file
    ssize_t bytesWritten = write(fd, bfr, strlen(bfr));
    if (bytesWritten == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("New ticket number: %s", bfr);

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
