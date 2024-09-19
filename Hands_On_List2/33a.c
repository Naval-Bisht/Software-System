/*
============================================================================================
File Name : 33a.c
Author : Naval Kishore Singh Bisht
Roll No : MT2024099
Description : 33. Write a program to communicate between two machines using socket.
Data : 19/09/2024
============================================================================================
*/

// client code

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<unistd.h>
int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char msg[] = "Hello from client!";
    send(sockfd, msg, sizeof(msg), 0);

    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}
