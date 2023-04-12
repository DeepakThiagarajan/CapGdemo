#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>
//#include "userver_functions.c"

#define MAXBUFF 100000
#define MAXCMD 100000
#define PORTNO 5449
#define MAX_PATH_LENGTH 100000
#define MAX_LINE_LENGTH 100000

void search(const char *path, const char *word);
void search_for_word(const char *path, const char *word, int *found_files, char **tokens, int *num_tokens);
void display_tokens();
#define MAX_TOKENS 100

int sfd = 0, retValue = 0, csfd = 0;
int clientAddlen = 0;

struct sockaddr_in serv_address, client_address;

char word[MAXBUFF] = {0,};
int main()
{
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
 	char choice[MAXBUFF];

	read(csfd,choice,MAXBUFF);
	switch(choice[0])
	{	
	case '1':
		printf("\nServer : Client will request to search for a word/char in RSE\n");
    		memset(word, '\0', MAXBUFF);
		memset(path, '\0',MAXBUFF);
        	read(csfd, word, MAXBUFF);
        	read(csfd, path, MAXBUFF);
        	printf("\n Searching for the word within the provided pathname\n");
        
        	printf("Search string is %s\n", word);
        	printf("The received path is :%s\n", path);
        	search(path, word);
		break;
  //      close(csfd);
	
	 case '2':
		break;
	
	 default:
		printf("Invalid choice");
		break;
	}
    }
//    close(sfd);

    return 0;
}
void search(const char *path, const char *word) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    // Iterate over all entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively search the subdirectory
            search(full_path, word);
        } else if (entry->d_type == DT_REG) {
            // Search the file for the word
            int found_files[MAX_TOKENS] = {0};
            char *tokens[MAX_TOKENS];
            int num_tokens = 0;
            search_for_word(full_path, word, found_files, tokens, &num_tokens);
        }
    }

    closedir(dir);
    display_tokens();
}

void search_for_word(const char *path, const char *word, int *found_files, char **tokens, int *num_tokens) {
    FILE *grep_output = NULL;
    char grep_command[MAX_PATH_LENGTH];
    sprintf(grep_command, "grep -r %s %s", word, path);
    grep_output = popen(grep_command, "r");
    if (grep_output == NULL) {
        fprintf(stderr, "Error: Could not run grep command\n");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, grep_output) != NULL) {
        char *filename = strtok(line, ":");
        if (filename == NULL) {
            continue;
        }
         if (found_files[atoi(filename)]) {
             continue;
         }
         found_files[atoi(filename)] = 1;
        tokens[*num_tokens] = strdup(filename);
        (*num_tokens)++;
        if (*num_tokens == MAX_TOKENS) {
            break;
        }
    }
    pclose(grep_output);
}

void display_tokens() {
    char line[MAX_LINE_LENGTH];
    FILE *fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.txt\n");
        return;
    }

    // Tokenize the file contents and display the tokens
    char *tokens[MAX_TOKENS];
    int num_tokens = 0;

    // Array to keep track of seen filenames
    char seen_filenames[MAX_TOKENS][MAX_PATH_LENGTH];
     int num_seen_filenames = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
      num_tokens++;
        strcpy(tokens[num_tokens],token);
        if (num_tokens == MAX_TOKENS) {
            break;
        }
    }

    fclose(fp);

    char msg[MAXBUFF];
    sprintf(msg,"Found %d files with the word\n", num_tokens);
    write(csfd,msg,MAXBUFF);
    bzero(msg,MAXBUFF);
    // Display the tokens
   // for (int i = 0; i < num_tokens; i++) {
   //     sprintf(msg,"%s. %s\n", j, tokens[i]);
   // }
   // write(csfd,msg,MAXBUFF);
    fseek(fp,0,SEEF_END); 
    long file_size = ftell(sp);
    rewind(fp);
 
    char *buffer = (char*) malloc(file_size +1);
    fread(buffer,1,file_size,fp);
    buffer[file_size] = '\0';
  
    send(csfd,buffer,file_size + 1, 0);

    free(buffer);

    // Prompt the user to select a file to display its contents
    char choice[MAXBUFF];
    sprintf(msg,"Enter the number of the file to display its contents (0 to exit): ");
    write(csfd,msg,strlen(msg));
    read(csfd,choice,strlen(choice));
    
    if (atoi(choice) >= 1 && atoi(choice) <= num_tokens) {
        FILE *file = fopen(tokens[atoi(choice)-1], "r");
        if (file == NULL) {
            sprintf(msg,"Error opening file: %s\n", tokens[atoi(choice)-1]);
            write(csfd,msg,strlen(msg));
        } else {
            
            sprintf(msg,"Contents of file: %s\n", tokens[atoi(choice)-1]);
            write(csfd,msg,strlen(msg));
            while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                printf("%s", line);
                write(csfd,line,strlen(line));
            }
            fclose(file);
        }
    }
}
