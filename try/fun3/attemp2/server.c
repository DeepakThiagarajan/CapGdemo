#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>

#define MAX 2048
#define MAX_LENGTH 2048
#define PORTNO 5449

char * openAbsolutePath(char * );

int main()
{
    int sfd = 0, retValue = 0, csfd = 0;
    int clientAddlen = 0;

    struct sockaddr_in serv_address, client_address;

    char msg[MAX];
    char path[MAX];

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd < 0)
    {
        perror("socket() ");
        exit(EXIT_FAILURE);
    }
    
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

    retValue = listen(sfd, 5);
    if (retValue < 0)
    {
        perror("listen() ");
        exit(EXIT_FAILURE);
    }


    while (1)
    {
        csfd = accept(sfd, (struct sockaddr *)&client_address, &clientAddlen);

        if (csfd < 0)
        {
            perror("accept() ");
            exit(EXIT_FAILURE);
        }
        printf("\nServer: Client got a connection\n");
	
        
        strcpy(msg,"Enter the path to search: \n");
        write(csfd,msg,MAX);
        bzero(msg,MAX);
        
        read(csfd,msg,MAX);
        strcpy(path,msg);
        bzero(msg,MAX);
	char *result = openAbsolutePath(path);
	write(csfd,result,MAX_LENGTH);
	bzero(result,MAX_LENGTH);
		
	}				
    close(csfd);
close(sfd);
    return 0;
}


char * openAbsolutePath(char * fpath) {
    
    char * buffer = (char *)malloc(100000);
  

    FILE * fptr = fopen(fpath, "r");
    if (fptr == NULL) {
        fprintf(stderr, "File not found or cannot be opened\n");
        free(buffer);
        return NULL;
    }


    size_t n = 0;
    char line[MAX];
    while (fgets(line, MAX_LENGTH, fptr) != NULL) {
        
            strcat(buffer, line);
   //         printf("\n%s\n",buffer);
            n += strlen(line);
    }
    

    fclose(fptr);

    return buffer;
}
