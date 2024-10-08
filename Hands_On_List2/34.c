/*
============================================================================================
File Name : 34.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 34. Write a program to create a concurrent server.
                    a. use fork
                    b. use pthread_create
Data : 19/09/2024
============================================================================================
*/
// using fork()

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

// to receive the file in another terminal 

//echo "Hello " | nc localhost 8080


int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sockfd, 5);

    while (1) {
        int client_socket = accept(sockfd, NULL, NULL);
        if (fork() == 0) {  // Create child process to handle client
            char buffer[1024];
            recv(client_socket, buffer, sizeof(buffer), 0);
            printf("Received: %s\n", buffer);

            char response[] = "Hello from server!";
            send(client_socket, response, sizeof(response), 0);
            close(client_socket);
            return 0;
        }
        close(client_socket);
    }
    close(sockfd);
    return 0;
}

