#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024
void send_file(int socket, const char *filename)
{
    int file = open(filename, O_RDONLY);
    if (file == -1)
    {
        perror("Error opening file");
        exit(1);
    }
    int file_size = lseek(file, 0, SEEK_END);
    char size_str[BUFFER_SIZE];
    sprintf(size_str, "%d", file_size);
    if (send(socket, size_str, BUFFER_SIZE, 0) == -1)
    {
        perror("Error sending file size");
        exit(1);
    }
    lseek(file, 0, SEEK_SET);
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int bytes_sent;
    while ((bytes_read = read(file, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_sent = 0;
        while (bytes_sent < bytes_read)
        {
            int n = send(socket, buffer + bytes_sent, bytes_read - bytes_sent, 0);
            if (n == -1)
            {
                perror("Error sending file data");
                exit(1);
            }
            bytes_sent += n;
        }
    }
    close(file);
}

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding socket");
        exit(1);
    }
    if (listen(server_socket, 5) == -1)
    {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1)
    {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1)
        {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Connected to client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        char filename[BUFFER_SIZE];
        if (recv(client_socket, filename, BUFFER_SIZE, 0) == -1)
        {
            perror("Error receiving filename");
            exit(1);
        }

        printf("Requested file: %s\n", filename);
        send_file(client_socket, filename);

        printf("File sent successfully\n");
        close(client_socket);

        printf("Disconnected from client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }
    close(server_socket);

    return 0;
}
