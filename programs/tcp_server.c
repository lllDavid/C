#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main() {
    WSADATA wsa;
    SOCKET server_sock, client_sock;
    struct sockaddr_in server, client;
    int client_len = sizeof(client);
    char buffer[512];
    int recv_size;

    WSAStartup(MAKEWORD(2,2), &wsa);

    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(server_sock, (struct sockaddr*)&server, sizeof(server));
    listen(server_sock, 3);

    printf("Waiting for connections...\n");
    client_sock = accept(server_sock, (struct sockaddr*)&client, &client_len);
    if (client_sock == INVALID_SOCKET) {
        printf("Accept failed\n");
        closesocket(server_sock);
        WSACleanup();
        return 1;
    }

    recv_size = recv(client_sock, buffer, sizeof(buffer)-1, 0);
    if (recv_size > 0) {
        buffer[recv_size] = '\0';
        printf("Received: %s\n", buffer);
        send(client_sock, buffer, recv_size, 0); 
    }

    closesocket(client_sock);
    closesocket(server_sock);
    WSACleanup();
    return 0;
}
