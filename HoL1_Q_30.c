//  Rollno: MT2024099 
//  Name : Naval Kishore Singh Bisht 
//  Question No 30 of Hands On List 1 
// 30. Write a program to run a script at a specific time using a Daemon process

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#define SCRIPT_PATH "/home/naval/SOFTWARE SYSTEM/HoL1_Q_30.sh"  // Define the path to the script

int main() {
    int target_hour, target_minute;
    printf("Enter target hour (24-hour format): ");
    scanf("%d", &target_hour);
    printf("Enter target minute: ");
    scanf("%d", &target_minute);

    // Fork the first time to create a background process
    int pid = fork();
    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process exits
        exit(0);
    }

    // Create a new session and become the session leader
    if (setsid() < 0) {
        perror("Failed to create a new session");
        exit(1);
    }

    // Fork the second time to ensure the daemon is not a session leader
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process exits
        exit(0);
    }

    // Set file mode creation mask to zero
    umask(0);

    // Change the working directory to root
    chdir("/");

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Daemon process loop
    while (1) {
        // Get the current time
        time_t current_time = time(NULL);
        struct tm *local_time = localtime(&current_time);

        // Check if the current time matches the target time
        if (local_time->tm_hour == target_hour && local_time->tm_min == target_minute) {
            // Prepare the arguments for execv
            char *args[] = {SCRIPT_PATH, NULL};
            execv(SCRIPT_PATH, args);  // Execute the script
            exit(0);  // Exit after executing the script
        }

        // Sleep for a random interval (1 to 10 seconds) to add randomness
        sleep(rand() % 10 + 1);
    }

    return 0;
}
