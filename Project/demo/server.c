#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 1024
#define PORTNO 4444

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
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

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
	
	printf("\nServer : Client will request to search for a word/char in RSE\n");
        memset(msg, '\0', MAXBUFF);
        read(csfd, msg, MAXBUFF);
        read(csfd, path, MAXBUFF);
        sprintf(command, "grep -r %s /%s", msg,path);
        FILE *fp = popen(command, "r");
        if (!fp)
        {
            perror("popen()");
            exit(EXIT_FAILURE);
        }
        char content[MAXBUFF];
        while (fgets(content, MAXBUFF, fp) != NULL)
        { 
           write(csfd, content, strlen(content));
//		printf("%s",content);
        }
        pclose(fp);
  //      close(csfd);
	printf("Server : Client will ask for file name to be searched in RSE\n");
	memset(msg,'\0',MAXBUFF);
	read(csfd,msg,MAXBUFF);
	char path1[MAXBUFF] = "/home2/trainee46/";
	sprintf(command,"find %s -name %s -type f",path1,msg);
	fp = popen(command,"r");
	if(!fp)
	{
		perror("popen()");
		exit(EXIT_FAILURE);
	}
	while(fgets(content,MAXBUFF,fp)!= NULL)
	{
		write(csfd, content, strlen(content));
	}	
	pclose(fp);


//        printf("Server: Client sent a msg: %s\n", msg);
    }
//    close(sfd);

    return 0;
}
