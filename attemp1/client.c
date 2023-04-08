#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 2048
#define MAX_LENGTH 100000
#define PORTNO 5449

int main()
{
    int sfd = 0, retValue = 0;
    int clientAddlen = 0;
    struct sockaddr_in serv_address;
    char *msg = (char *)malloc(MAX_LENGTH);
    char *result = (char *)malloc(MAX_LENGTH);
    
    printf("\n TO OPEN ABSOLUTE PATH FILE USING SERVER AND CLIENT WITH FILE SIZE LESS THAN 100000\n");

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
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.2");

    retValue = connect(sfd, (struct sockaddr *)&serv_address, sizeof(serv_address));
    if (retValue < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }
    printf("\nClient: Connected to the server\n");
    
       	

	read(sfd,msg,MAX);
    printf("%s",msg);  // Enter the path to search:
    bzero(msg,MAX_LENGTH);
    
    scanf("%s",msg);  // /home2/trainee46/base/CapGdemo/sample.c
    write(sfd,msg,strlen(msg));
    bzero(msg,MAX_LENGTH);
    
    
    read(sfd,msg,MAX_LENGTH);   //tokenized content
    printf("\n%s\n",msg);
    free(msg);
                   
    close(sfd);
    return 0;
}
