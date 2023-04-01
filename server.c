#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 1024
#define PORTNO 4003

int main()
{
    int sfd = 0, retValue = 0, csfd = 0;
    int clientAddlen = 0;

    struct sockaddr_in serv_address, client_address;

    char msg[MAXBUFF] = {0,};
    char path[MAXBUFF] = {0,};
    char command[MAXBUFF];

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd < 0)
    {
        perror("socket() ");
        exit(EXIT_FAILURE);
    }
    printf("\nSocket created with sockfd : %d", sfd);

    // reset/set address of server 

    memset(&serv_address, '\0', sizeof(serv_address));

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(PORTNO);
    serv_address.sin_addr.s_addr = INADDR_ANY;

    retValue = bind(sfd, (struct sockaddr *)&serv_address, sizeof(serv_address));
    if (retValue < 0)
    {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    printf("\nBinded the server to the ipaddress with portno\n");

    retValue = listen(sfd, 5);
    if (retValue < 0)
    {
        perror("listen() ");
        exit(EXIT_FAILURE);
    }
    printf("\nListening to the clients now\n");

    while (1)
    {
        csfd = accept(sfd, (struct sockaddr *)&client_address, &clientAddlen);

        if (csfd < 0)
        {
            perror("accept() ");
            exit(EXIT_FAILURE);
        }
        printf("\nServer: Client got a connection\n");

        strcpy(msg, "====================================================\n");
        strcat(msg, "\n=============Welcome to Capgemini Server=============\n");
        strcat(msg, "====================================================\n");

        write(csfd, msg, strlen(msg));

        memset(msg, '\0', MAXBUFF);
        read(csfd, msg, MAXBUFF);
        read(csfd, path, MAXBUFF);
        sprintf(command, "grep -r --include=*.{txt,c} '%s' '%s'", msg, path);
        FILE *fp = popen(command, "r");
        if (fp == NULL)
        {
            perror("popen()");
            exit(EXIT_FAILURE);
        }
        memset(msg, '\0', MAXBUFF);
        int i = 0;
        while (fgets(msg, MAXBUFF, fp) != NULL)
        {
            char content[MAXBUFF];
            sprintf(content, "%d--%s", i++, msg);

            int n = write(csfd, content, strlen(content));
            if (n < 0)
            {
                perror("ERROR WRITING TO SOCKET");
                exit(EXIT_FAILURE);
            }
            memset(msg, '\0', MAXBUFF);
        }
        pclose(fp);
        close(csfd);

        printf("Server: Client sent a msg: %s\n", msg);
    }
    close(sfd);

    return 0;
}
