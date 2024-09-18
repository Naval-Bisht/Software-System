/*
============================================================================================
File Name : 15.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 15. Write a simple program to send some data from parent to the child process.
Data : 18/09/2024
============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {  // Child process
        close(fd[1]);  // Close write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));  // Read from pipe
        printf("Child Got this message: %s\n", buffer);
        close(fd[0]);
    } 
    else {  // Parent process
        close(fd[0]);  // Close read end
        char msg[] = "hi this is the parent data !";
        write(fd[1], msg, strlen(msg) + 1);  // Write to pipe
        close(fd[1]);
    }

    return 0;
}

/*
Explanation:
1. pipe(pipefd): Creates a pipe with two file descriptors: pipefd[0] for reading and pipefd[1] for writing.
2. fork(): Creates a child process. Both parent and child share the pipe.
3. The parent writes to the pipe, and the child reads from it.
4. It's important to close the unused ends of the pipe in both processes to prevent deadlocks.

Alternative Approaches:
- Use `popen()` for simpler pipe creation between processes if you need to execute commands instead of handling raw data.
- You can use named pipes (FIFOs) if you need inter-process communication across unrelated processes.

1. This is similar to the previous program but simplifies the data exchange to only sending a message from the parent to the child.
2. The pipe mechanism is used to communicate between the two related processes.
3. The child reads the data sent by the parent.

Alternative Approaches:
- You could use message queues for a more structured message-passing mechanism.
- Shared memory could also be used for communication between parent and child processes.

For more details, use the following man pages:
- man 2 pipe
- man 2 fork
- man 7 mq_overview (for message queues)
*/
