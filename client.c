#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 1024
#define PORTNO 7799
#define MAXLEN 50

int main()
{
    int sfd = 0, retValue = 0, c;
    int clientAddlen = 0;
    struct sockaddr_in serv_address;
    char msg[MAXBUFF] = {0};
    char path[MAXBUFF] = {0};
    char *username = getlogin();
    strcat(path, "/home2/");
    strcat(path, username);
    strcat(path, "/");
    
    int search = 0;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("socket() ");
        exit(EXIT_FAILURE);
    }
    printf("\nSocket created with sockfd : %d", sfd);

    // Reset/set address of server 
    memset(&serv_address, 0, sizeof(serv_address));
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORTNO);
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    retValue = connect(sfd, (struct sockaddr *)&serv_address, sizeof(serv_address));
    if (retValue < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }
    printf("\nClient: Connected to the server\n");

    // Request the server to search for a file
    printf("\nEnter the word/char to search \n");
    scanf("%s", msg);
    write(sfd, msg, strlen(msg));
    
    printf("Any specific path(y for 1/n for 2) \n");
    scanf("%d", &c);
    char userpath[MAXLEN];
    
    switch(c)
    {
        case 1:
            printf("Enter the path\n");
            printf("%s", path);
            fgets(userpath, MAXLEN, stdin);
            userpath[strlen(userpath)-1] = '\0';
            strcat(path, userpath);
            strcat(path, "/");
            printf("Searching with abspath ..\n");
            write(sfd, path, 1000);
            break;
        case 2:
            printf("Searching without abspath ..\n");
            printf("%s", path);
            write(sfd, path, 1000);
            break;
        default:
            fprintf(stderr, "Invalid Choice !!\n");
            break;
    }
    memset(msg, 0, MAXBUFF);
    read(sfd, msg, MAXBUFF);
    printf("%s", msg);

    // Close the socket
    close(sfd);

    return 0;
}
