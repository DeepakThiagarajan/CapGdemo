#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAXBUFF 1024

int main()
{
    int sfd=0, retValue=0, csfd=0;
    int clientAddrlen=0;

    struct sockaddr_in serv_address,client_address;
    char msg[MAXBUFF] = {0, };
    sfd = socket(AF_INET,SOCK_STREAM,0);
    if(sfd < 0)
    {
        perror("socket()");
        exit(EXIT_FAILURE);
    }
    printf("\n Socket created with sfd: %d",sfd);
    
    memset(&serv_address,'0',sizeof(serv_address)); //change '0' to 0
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(7922);
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.1"); //add missing '(' and ')' around IP address
    
    retValue = bind(sfd,(struct sockaddr *)&serv_address,sizeof(serv_address));
    if(retValue < 0)
    {
        perror("bind()"); //correct typo
        exit(EXIT_FAILURE);
    }
    printf("\n Binded the server to ipaddress with portno \n");
    
    retValue = listen(sfd,5);
    if(retValue < 0)
    {
        perror("listen()");
        exit(EXIT_FAILURE);
    }
    printf("\n Listening to clients !! \n");
    
    csfd = accept(sfd,(struct sockaddr *)&client_address,&clientAddrlen);
    if(csfd < 0)
    {
        perror("accept()");
        exit(EXIT_FAILURE);
    }
    printf("\n Server: Client got a Connection \n");
    
    return 0;
}
