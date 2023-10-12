#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) == 0)
    {
        printf("Listening...\n");
    }
    else
    {
        perror("Error in listening");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    // Accept a connection from a client
    new_socket = accept(server_fd, (struct sockaddr *)&new_addr, &addr_size);

    // Read data from the client and send a response
    while (1)
    {
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        recv(new_socket, buffer, sizeof(buffer), 0);
        printf("Client: %s", buffer);
        buffer[4] = '\0';
        if (!strcmp(buffer, "exit"))
        {
            printf("Client wants to disconnect...\n");
            break;
        }
        else
        {
            memset(buffer, 0, sizeof(buffer)); // Clear the buffer
            printf("Server: ");
            fgets(buffer, sizeof(buffer), stdin);
            send(new_socket, buffer, strlen(buffer), 0);
            buffer[4] = '\0';
            if (!strcmp(buffer, "exit"))
            {
                printf("Server exiting...\n");
                break;
            }
        }
    }

    // Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}
