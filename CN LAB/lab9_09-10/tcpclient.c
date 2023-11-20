#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in connection");
        exit(1);
    }

    // Read data from the user and send it to the server
    while (1)
    {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);
        buffer[4] = '\0';
        int check = strcmp(buffer, "exit");
        if (!strcmp(buffer, "exit"))
        {
            printf("Client exiting...\n");
            break;
        }

        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Server: %s", buffer);
        buffer[4] = '\0';
        if (!strcmp(buffer, "exit"))
        {
            printf("Server wants to disconnected....\n");
            break;
        }
    }

    // Close the socket
    close(client_socket);

    return 0;
}

