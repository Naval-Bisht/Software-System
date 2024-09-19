/*
============================================================================================
File Name : 34a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 34. Write a program to create a concurrent server.
                    a. use fork
                    b. use pthread_create
Data : 19/09/2024
============================================================================================
*/

// using pthread

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include<unistd.h>

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[1024];
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    char response[] = "Hello from server!";
    send(sock, response, sizeof(response), 0);
    close(sock);
    return NULL;
}

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
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        pthread_detach(thread_id);  // Detach the thread to handle client independently
        
    }
    close(sockfd);
    return 0;
}

