/*
============================================================================================
File Name : 33.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 33. Write a program to communicate between two machines using socket.
Data : 19/09/2024
============================================================================================
*/

// server code


#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sockfd, 5);

    int client_socket = accept(sockfd, NULL, NULL);

    char buffer[1024];
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    char response[] = "Hello from server!";
    send(client_socket, response, sizeof(response), 0);

    close(client_socket);
    close(sockfd);
    return 0;
}
