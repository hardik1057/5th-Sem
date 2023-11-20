// Client program for receiving a file via TCP sockets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define SERVER_IP "127.0.0.1" 
#define SERVER_PORT 8080      
#define BUFFER_SIZE 1024      
void receive_file(int socket, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Error creating file");
        exit(1);
    }
    char size_str[BUFFER_SIZE];
    int bytes_received = recv(socket, size_str, BUFFER_SIZE, 0);
    if (bytes_received == -1)
    {
        perror("Error receiving file size");
        exit(1);
    }
    int file_size = atoi(size_str);
    char buffer[BUFFER_SIZE];
    while (file_size > 0)
    {
        bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1)
        {
            perror("Error receiving file data");
            exit(1);
        }
        fwrite(buffer, 1, bytes_received, file);
        file_size -= bytes_received;
    }
    fclose(file);
}

int main()
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(SERVER_PORT);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to server %s:%d\n", SERVER_IP, SERVER_PORT);
    char filename[BUFFER_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    if (send(client_socket, filename, BUFFER_SIZE, 0) == -1)
    {
        perror("Error sending filename");
        exit(1);
    }

    printf("Requested file: %s\n", filename);
    receive_file(client_socket, filename);

    printf("File received successfully\n");
    close(client_socket);
    return 0;
}
