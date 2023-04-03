#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 1024
#define PORTNO 4447
#define MAXLEN 50

int main()
{
    int sfd = 0, retValue = 0, c;
    int clientAddlen = 0;
    struct sockaddr_in serv_address;
    char msg[MAXBUFF] = {0};
    char buf[MAXBUFF] = {0};
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
    
    char ch[MAXBUFF];
    printf("\n -----------------------------------------------------------\n");
    printf("\nSelect an option\n 1 - to search a word/string\n 2 - to search a filename\n");
    scanf("%s",ch);
    getchar();
    if(strlen(ch) > 1){
	ch[0] = '7';
    }

    printf("\n -----------------------------------------------------------\n");
    //switch case 
    switch(ch[0])
    {
	case 1:
		 // Request the server to search for a file
		  printf("\nEnter the word/char to search \n");
                  scanf("%s", msg);
                  write(sfd, msg, strlen(msg));
    
    		  printf("\n -----------------------------------------------------------\n");
                  printf("Any specific path(y for 1/n for 2) \n");
                  scanf("%d", &c);
                  char userpath[MAXLEN];
    
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
    
    		  read(sfd, buf, MAXBUFF);
    	          printf("\n%s", buf);
	          break;
    
           case 2:
			
		printf("\n -----------------------------------------------------------\n");
    		printf("\n Enter the file name to be searched \n");
                scanf("%s",msg);
    		printf("\n -----------------------------------------------------------\n");
                write(sfd,msg,strlen(msg));

                memset(buf,'\0',MAXBUFF); 
                read(sfd,buf,MAXBUFF); 
                printf("/n%s",buf);
                break;

           default:
		
  		printf("Invalid!!!\n");
	  	break;
                   
                     
      }
    // Close the socket
//    close(sfd);

    return 0;
}
