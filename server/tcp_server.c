#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    printf("Listening on port %d...\n", PORT);

    client_fd = accept(server_fd, NULL, NULL);

    printf("Client connected\n");

    while (1)
    {
        int bytes = read(client_fd, buffer, BUFFER_SIZE);

        if (bytes <= 0)
            break;

        buffer[bytes] = '\0';

        printf("Client: %s\n", buffer);

        char *response = "Received\n";
        write(client_fd, response, strlen(response));
    }
    close(client_fd);
    close(server_fd);

    return 0;
}
