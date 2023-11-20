#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUMBER 8080

void reverseString(char *str)
{
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; ++i, --j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

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
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &addr_len);
    if (bytes_received < 0)
    {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';

    printf("Received from client: %s\n", buffer);

    // Reverse the received string
    reverseString(buffer);

    int bytes_sent = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, addr_len);
    if (bytes_sent < 0)
    {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}
