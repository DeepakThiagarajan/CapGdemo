#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>
#include "functions.c"

#define MAXBUFF 100000
#define MAXCMD 100000
#define PORTNO 5449

int main()
{
    int sfd = 0, retValue = 0, csfd = 0;
    int clientAddlen = 0;

    struct sockaddr_in serv_address, client_address;

    char msg[MAXBUFF] = {0,};
    char path[MAXBUFF] = {0,};
    char command[MAXCMD];

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
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.2");

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
		
        	memset(msg, '\0', MAXBUFF);
        	read(csfd, msg, MAXBUFF);
		char word[MAXBUFF];
		strcpy(word,msg);

		bzero(msg,MAXBUFF);
        	read(csfd,msg, MAXBUFF);
		char path[MAXBUFF];
		strcpy(path,msg);
		
		bzero(msg,MAXBUFF);		
		strcpy(msg,search(path,word));
		write(csfd,msg,strlen(msg));
	
		char sorf[MAXBUFF];
		read(csfd,msg,strlen(msg));
		strcpy(sorf,msg);
		if(strcmp(sorf,"SUCCESS")== 0)
		{	
			strcpy(msg, display_tokens());
			write(csfd,msg,strlen(msg));
			read(csfd,msg,strlen(msg));
			
			strcpy(msg ,displ2("1"));
			write(csfd,msg,strlen(msg));
		}
		
	}				
    close(sfd);

    return 0;
}
