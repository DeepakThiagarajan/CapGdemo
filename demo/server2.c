#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>

#define MAXBUFF 100000
#define MAXCMD 100000
#define PORTNO 5449

struct FileNode {
    char *filename;
    struct FileNode *next;
};

typedef struct FileNode FileNode;

int search_files(char *dir_path, char *search_term, FileNode **head_ref, FileNode **curr_ref);
int count_files(FileNode *head);
FileNode *find_file_by_index(FileNode *head, int index);
void read_file_contents(char *filename, char *buffer, int buffer_size);
void free_files(FileNode *head);

int main()
{
    int sfd = 0, retValue = 0, csfd = 0, pid, n;
    unsigned int clientAddlen = 0;

    struct sockaddr_in serv_address, client_address;

    char msg[MAXBUFF] = {0,};
    char path[MAXBUFF] = {0,};
    char command[MAXCMD]={0,};

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
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.4");

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


        pid = fork();
        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0) {  // Child process
            close(sfd);

            char path[MAXBUFF], search_term[MAXBUFF], results[MAXBUFF];
            memset(path, 0, MAXBUFF);
            memset(search_term, 0, MAXBUFF);
            memset(results, 0, MAXBUFF);

            // Read search path and term from client
            n = read(csfd, path, MAXBUFF);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            n = read(csfd, search_term, MAXBUFF);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            // Search for files
            FileNode *head = NULL, *curr = NULL;
            int ret = search_files(path, search_term, &head, &curr);
            if (ret == EXIT_FAILURE) {
                strncpy(results, "No results found.\n", MAXBUFF - 1);
            } else {
                // Build response string
                memset(results, 0, MAXBUFF);
                FileNode *file = head;
                while (file != NULL) {
                    strncat(results, file->filename, MAXBUFF - strlen(results) - 1);
                    strncat(results, "\n", MAXBUFF - strlen(results) - 1);
                    file = file->next;
                }
            }

            // Send response to client
            n = write(csfd, results, strlen(results));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            // Clean up and exit child process
            free_files(head);
            close(csfd);
            exit(0);
        } else {  // Parent process
            close(csfd);
        }
    }

    return 0;
}


int search_files(char *dir_path, char *search_term, FileNode **head_ref, FileNode **curr_ref) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dir_path))) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[MAXBUFF];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, MAXBUFF, "%s/%s", dir_path, entry->d_name);
            search_files(path, search_term, head_ref, curr_ref);
        } else {
            if (strstr(entry->d_name, search_term) != NULL) {
                FileNode *new_node = (FileNode *)malloc(sizeof(FileNode));
                new_node->filename = strdup(entry->d_name);
                new_node->next = NULL;
                if (*head_ref == NULL) {
                    *head_ref = new_node;
                    *curr_ref = new_node;
                } else {
                    (*curr_ref)->next = new_node;
                    *curr_ref = new_node;
                }
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}

int count_files(FileNode *head) {
    int count = 0;
    FileNode *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

FileNode *find_file_by_index(FileNode *head, int index) {
    int i = 0;
    FileNode *curr = head;
    while (curr != NULL) {
        if (i == index) {
            return curr;
        }
        i++;
        curr = curr->next;
    }
    return NULL;
}

void read_file_contents(char *filename, char *buffer, int buffer_size) {
    FILE *fp;
    int num_read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    num_read = fread(buffer, sizeof(char), buffer_size, fp);
    buffer[num_read] = '\0';

    fclose(fp);
}

void free_files(FileNode *head) {
    FileNode *curr = head;
    FileNode *prev = NULL;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev->filename);
        free(prev);
    }
}






