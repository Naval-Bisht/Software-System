/*
============================================================================================
File Name : 11.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 11. Write a program to ignore a SIGINT signal then reset the default action 
                    of the SIGINT signal -use sigaction system call.
Data : 17/09/2024
============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGINT
void signal_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGINT (Ctrl + C)\n");
}

int main() {
    struct sigaction action;

    // Ignore SIGINT signal
    action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &action, NULL);
    printf("SIGINT signal is ignored. Try pressing Ctrl + C.\n");
    sleep(5);

    // Reset SIGINT to default action
    action.sa_handler = SIG_DFL;
    sigaction(SIGINT, &action, NULL);
    printf("SIGINT signal action reset to default. Try pressing Ctrl + C again.\n");

    // Wait for signal
    while (1) {
       
    }

    return 0;
}

/*
Explanation:
1. action.sa_handler = SIG_IGN: Ignores the SIGINT signal by setting the handler to SIG_IGN.
2. sigaction(SIGINT, &action, NULL): Sets the action for the SIGINT signal.
3. sleep(5): Gives the user 5 seconds to test that SIGINT is ignored.
4. action.sa_handler = SIG_DFL: Resets the signal handler to the default action.
5. The program waits for the SIGINT signal using pause() after resetting it to the default.

Alternative Approaches:
- Use `signal()` if simpler signal handling (ignoring and resetting) is sufficient.
- You can add signal masking to temporarily block signals using `sigprocmask()`.

For more details, use the following man pages:
- man 2 sigaction
- man 2 sigprocmask
*/
