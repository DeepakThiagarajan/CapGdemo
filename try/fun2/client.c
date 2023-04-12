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


int main()
{
    int sfd = 0, retValue = 0,c;
    int clientAddlen = 0;
    struct sockaddr_in serv_address;
    char *msg = (char *)malloc(MAXBUFF);
    char *result = (char *)malloc(MAXBUFF);
    char path[MAXBUFF] = {0,};
    char *username = getlogin();
    strcat(path, "/home2/");
    strcat(path, username);
    strcat(path, "/");
    

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
    
    char ch[1];
    printf("\n -----------------------------------------------------------\n");
    printf("\nSelect an option\n 1 - to search a word/string\n 2 - to search a filename\n3 - to open absolute path\n4 - Quit");
    scanf("%s",ch);
//     getchar();
//     if(strlen(ch) > 1){
// 	ch[0] = '7';
//     }
    write(sfd,ch,strlen(ch));
    printf("\n -----------------------------------------------------------\n");
    //switch case 
    switch(ch[0])
    {
	case '1':
		 // Request the server to search for a file
		 printf("\nEnter the word/char to search \n");
		 scanf("%s", msg);
		 write(sfd, msg, strlen(msg));
    
    	printf("\n -----------------------------------------------------------\n");
        printf("Any specific path(y for 1/n for 2) \n");
        scanf("%d", &c);
        char userpath[MAXBUFF];
    
        switch(c)
        {
            case 1:
                
                printf("The Base Path Name");
	    	    printf("%s\n", path);
                printf("Enter the path\n");
            	scanf("%s",userpath);
            	userpath[strlen(userpath)-1] = '\0';
            	strcat(path, userpath);
           	    strcat(path, "/");
            	printf("Searching with abspath ..\n");
            	write(sfd, path, 1000);
            	break;

            case 2:

            	printf("The Base Path Name");
            	printf("%s\n", path);
            	printf("Searching wih base path ..\n");
            	write(sfd, path, 1000);
            	break;
            	
            default:

            	fprintf(stderr, "Invalid Choice !!\n");
            	break;
    	}
    
    	read(sfd, result, MAXBUFF);
    	printf("\n%s", result);
    	bzero(result,MAXBUFF);
	break;
    
    case '2':
			
	    printf("\n -----------------------------------------------------------\n");
    	printf("\n Enter the file name to be searched \n");
        scanf("%s",msg);
    	printf("\n -----------------------------------------------------------\n");
        write(sfd,msg,strlen(msg));


        read(sfd,result,MAXBUFF); 
        printf("/n%s",result);
        bzero(result,MAXBUFF);
        break;
    
    case '3':
    
            read(sfd,msg,MAXBUFF);
            printf("%s",msg);  // Enter the path to search:
            bzero(msg,MAXBUFF);
    
            scanf("%s",msg);  // /home2/trainee46/base/CapGdemo/sample.c
            write(sfd,msg,strlen(msg));
            bzero(msg,MAXBUFF);
    
    
            read(sfd,msg,MAXBUFF);   //tokenized content
            printf("\n%s\n",msg);
            free(msg);
        
        break;
    case '4':
	
	printf("Exiting the Client Connection\n");
	break;

    default:
		
        printf("Invalid!!!\n");
	break;
                   
                     
    }

    return 0;
}
