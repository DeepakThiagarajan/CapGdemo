#include <utility.h>

int sfd = -1;

void ClientSignalHandler(int sig){
	printf("Recived Signal\nwith id : %d\n", sig);
	close(sfd);
	exit(sig);
}


int main(int argc, char *argv[])
{

    struct sockaddr_in server;
    int sfd = 0;
    int connfd = -1;
    int ret = -1;
    char buf[100000];
    char fileC[1000000];
    char file_contents[100000];
    char y_or_n;
    
    //char msg[MAXBUFF] = {0};
    //char buf[MAXCMD] = {0};
    char path[100000] = {0,};
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
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(MYPORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.2");

    connfd = connect(sfd, (struct sockaddr *)&server, sizeof(server));
    if (connfd < 0) {
        perror("connect()");
        close(sfd);
        exit(EXIT_FAILURE);
    }
    printf("\nClient: Connected to the server\n");
    
    send(sfd,path,MAX,0);

    while (1)
    {
    	system("clear");


    	printf("**********************************************\n");
    	printf("     WELCOME TO REMOTE SEARCH ENGINE          \n");
    	printf("**********************************************\n\n");
        printf("\n1.Search by String. \n2.Search by PATH. \n3.EXIT. \nEnter your choice: "); //menu driven interface
        char choice;
        scanf(" %c", &choice); //taking user choice of searching
        getchar();
        if(choice=='1'||choice=='2'||choice=='3')
        {
        	char choice_buf[2] = {choice, '\0'};   
        	ret = send(sfd, choice_buf, sizeof(choice_buf), 0);
        	if (FAILURE == ret)
        	{
            		perror("\nCLIENT: ERROR IN WRITING OPTION!!!\n");
            		return FAILURE;
        	}
        	char search[MAX],file_search[MAX];
        	fflush(NULL);
        
        	if (choice == STRING_CHOICE)                                          //RSE 2 and 4
        	{
            	printf("Please enter string/word/sentence to search: "); //passing string for searching
            	fgets(search, sizeof(search), stdin);
            	search[strcspn(search, "\n")] = 0;
            	search[strlen(search)] = '\0';
            	ret = write_data(sfd, search);
            	if (FAILURE == ret)
            	{
                	perror("\nCLIENT: ERROR IN WRITING SEARCH!!!\n");
					close(sfd);
                	return FAILURE;
            	}

            	ret = read(sfd, &buf, sizeof(buf));
            	if (-1 == ret)
            	{
                	perror("\nCLIENT: ERROR IN READING BUFF(FILE NAMES)!!\n");
					close(sfd);
                	return FAILURE;
            	}
            	if(strcmp("-1", buf) == 0){
            		printf("No Entry of the String\n");
            		printf("Continue? [y/n]\n");      //checking if user wants to continue
        		scanf(" %c", &y_or_n);
        		if(y_or_n == 'n'){
        			send(sfd, "3", sizeof("3"), 0);
        			break;
        		}
        		else{
        			continue;
        		}
            	}
            	printf("\nfiles are:\n");
            	printf("%s\n", buf);
            
            	printf("View Contents of File? [y/n]\n");
            	scanf(" %c", &y_or_n);
            	char fileNum[5];
            	if(y_or_n=='y'||y_or_n=='Y'||y_or_n=='n'||y_or_n=='N')
            	{
            		if(y_or_n == 'y' || y_or_n == 'Y'){
            			printf("Enter the file number: "); //showing the content according to the input number
            			scanf("%s", fileNum);
            			ret = send(sfd, fileNum, sizeof(fileNum), 0);
            		if (FAILURE == ret)
            		{
                		perror("\nCLIENT: ERROR IN WRITING FILE NUMBER!!!\n");
						close(sfd);
                		return FAILURE;
            		}
            		ret = read(sfd, &file_contents, sizeof(buf));
            		if (-1 == ret)
            		{
                		perror("\nCLIENT: ERROR IN READING FILE CONTENTS!!\n");
				close(sfd);
                		return FAILURE;
            		}
            		printf("\n files contents are: %s\n", file_contents);        //showing file Contents
            
            		}
            	else{
            		send(sfd, "0", sizeof("0"), 0);
            	}
            	bzero(search,sizeof(search));
            	bzero(buf,sizeof(buf));
            	bzero(fileNum,sizeof(fileNum));
            	bzero(file_contents,sizeof(file_contents));
            }
            else
            {
            	printf("enter a valid choice\n");
            }

        }

        else if (choice == PATH_CHOICE)
        {
            printf("Enter file name:");
            fgets(file_search, sizeof(file_search), stdin); //taking absolute path rse3
            file_search[strcspn(file_search, "\n")] = 0;
            file_search[strlen(file_search)] = '\0';
            printf("File name:%s", file_search);  
            ret = write_data(sfd, file_search);
            if (FAILURE == ret)
            {
                perror("\nCLIENT: ERROR IN WRITING SEARCH(FILENAME)!!!\n");
                close(sfd);
		return FAILURE;
            }
            memset(&fileC, 0, sizeof(fileC));
            ret = recv(sfd, &fileC, sizeof(fileC), 0);
            if (-1 == ret)
            {
                perror("\nCLIENTERROR IN READING FILE CONTENTS!!\n");
		close(sfd);
                return FAILURE;
            }
            printf("\nFiles contents are: %s\n", fileC);
            bzero(file_search,sizeof(file_search));
            bzero(fileC,sizeof(fileC));
        }

        else if (choice == EXIT_CHOICE)
        {
            exit(EXIT_SUCCESS);
        }
        }
        else
        {
            printf("Enter valid option\n");
        }
        printf("Continue? [y/n]\n");
        scanf(" %c", &y_or_n);
        printf("Exiting from the Search engine! \n");
        if(y_or_n == 'n'){
        	send(sfd, "3", sizeof("3"), 0);  //exiting file
        	break;
        }
        fflush(NULL);
    }
    close(sfd);
    return SUCCESS;
}
