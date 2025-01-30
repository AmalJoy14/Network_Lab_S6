#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 4000

int main() {
    int m, n = 100, sockfd, addr = sizeof(struct sockaddr_in);
    char buf[1025];
    struct sockaddr_in y;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    y.sin_family = AF_INET;
    y.sin_port = htons(PORT);
    y.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Connecting....\n");

    while (1) {
        printf("Message to be sent: ");
        scanf("%s", buf);
        sendto(sockfd, buf, n, 0, (struct sockaddr*)&y, addr);

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        printf("Message sent. Waiting for the response...\n");

        n = recvfrom(sockfd, buf, 1024, 0, (struct sockaddr*)&y, &addr);
        buf[n] = '\0'; // Null-terminate the received message.

        if (n > 1) {
            printf("\nReceived: %s\n", buf);
        }
    }

    close(sockfd);
    return 0;
}

