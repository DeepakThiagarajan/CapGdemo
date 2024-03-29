#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 100000
#define PORTNO 5449
#define MAXLEN 50
#define MAXCMD 100000

int main()
{
    int sfd = 0, retValue = 0, c;
    int clientAddlen = 0;
    struct sockaddr_in serv_address;
    char msg[MAXBUFF] = {0};
    char buf[MAXCMD] = {0};
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
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.4");

    retValue = connect(sfd, (struct sockaddr *)&serv_address, sizeof(serv_address));
    if (retValue < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }
    printf("\nClient: Connected to the server\n");

    printf("\nEnter the word/char to search: ");
    scanf("%s", msg);
    
    // Send the search string to the server
    write(sfd, path, strlen(path));
    
    // Send the base path name to the server
    write(sfd, msg, strlen(msg));
    
    // Receive the search results from the server
    read(sfd, buf, MAXCMD);
    
    // Print the search results
    printf("\nSearch Results:\n%s\n", buf);

    // Close the socket
    close(sfd);

    return 0;
}
