#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUMBER 8080

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUMBER);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter a string: ");
    char message[MAX_BUFFER_SIZE];
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline from fgets input

    int bytes_sent = sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0)
    {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    char echoed_message[MAX_BUFFER_SIZE];
    socklen_t addr_len = sizeof(server_addr);

    int bytes_received = recvfrom(sockfd, echoed_message, sizeof(echoed_message), 0, (struct sockaddr *)&server_addr, &addr_len);
    if (bytes_received < 0)
    {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }

    echoed_message[bytes_received] = '\0';
    printf("Received from server (reversed): %s\n", echoed_message);

    close(sockfd);
    return 0;
}
