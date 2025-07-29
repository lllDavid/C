#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
// clang client.c -lws2_32 -o client.exe
int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char buffer[512];
    int recv_size;

    WSAStartup(MAKEWORD(2,2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        printf("Could not create socket\n");
        WSACleanup();
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    while (1) {
        printf("Enter message to send (or 'quit' to exit): ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break;
        }

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        buffer[strcspn(buffer, "\r\n")] = 0;

        send(sock, buffer, strlen(buffer), 0);

        recv_size = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (recv_size <= 0) {
            printf("Connection closed by server or error\n");
            break;
        }
        buffer[recv_size] = '\0';
        printf("Echo from server: %s\n", buffer);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}