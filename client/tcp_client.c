#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

    connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));

    while (1)
    {
        printf(">> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        write(sock, buffer, strlen(buffer));

        int bytes = read(sock, buffer, BUFFER_SIZE - 1);

        if (bytes <= 0)
            break;

        buffer[bytes] = '\0';

        printf("Server: %s", buffer);
    }
    close(sock);
    return 0;
}
