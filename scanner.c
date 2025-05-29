#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return 0;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    int result = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    close(sock);

    return result == 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <max_port>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int max_port = atoi(argv[2]);

    printf("Scanning %s from port 1 to %d...\n", ip, max_port);

    for (int port = 1; port <= max_port; port++) {
        if (scan_port(ip, port)) {
            printf("Port %d is OPEN\n", port);
        }
    }

    return 0;
}
