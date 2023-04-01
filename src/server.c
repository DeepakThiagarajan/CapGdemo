#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <dirent.h>

#define PORT 8080
#define MAXLINE 1024
#define MAX_LENGTH 256

char path[MAX_LENGTH] = "";

void searchByWord(int new_socket, char *search_term) {
    char result[MAXLINE] = {0};
    DIR *dir;
    struct dirent *ent;
    char filepath[MAX_LENGTH] = "";

    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                snprintf(filepath, MAX_LENGTH, "%s%s", path, ent->d_name);
                FILE *fp = fopen(filepath, "r");
                if (fp == NULL) {
                    printf("Could not open file %s\n", filepath);
                    continue;
                }
                char line[MAXLINE];
                while (fgets(line, MAXLINE, fp) != NULL) {
                    if (strstr(line, search_term) != NULL) {
                        strncat(result, filepath, MAXLINE - strlen(result) - 1);
                        strncat(result, "\n", MAXLINE - strlen(result) - 1);
                        break;
                    }
                }
                fclose(fp);
            }
        }
        closedir(dir);
    } else {
        printf("Could not open directory %s\n", path);
    }

    if (strlen(result) == 0) {
        snprintf(result, MAXLINE, "No files containing '%s' found.\n", search_term);
    }

    send(new_socket, result, strlen(result), 0);
}

// void searchByFilename(int new_socket, char *filename) {
//     char result[MAXLINE] = {0};
//     DIR *dir;
//     struct dirent *ent;
//     char filepath[MAX_LENGTH] = "";

//     if ((dir = opendir(path)) != NULL) {
//         while ((ent = readdir(dir)) != NULL) {
//             if (ent->d_type == DT_REG && strcmp(ent->d_name, filename) == 0) {
//                 strcpy(result, "File '");
//                 strncat(result, filename, MAXLINE - strlen(result) - 1);
//                 strncat(result, "' found at '", MAXLINE - strlen(result) - 1);
//                 strncat(result, path, MAXLINE - strlen(result) - 1);
//                 strncat(result, filename, MAXLINE - strlen(result) - 1);
//                 strncat(result, "'\n", MAXLINE - strlen(result) - 1);
//                 break;
//             }
//         }
//         closedir(dir);
//     } else {
//         printf("Could not open directory %s\n", path);
// snprintf(result, MAXLINE, "Error: Could not open directory '%s'\n", path);
// send(new_socket, result, strlen(result), 0);
// return;
// }

//        if (strlen(result) == 0) {
//   	 snprintf(result, MAXLINE, "File '%s' not found.\n", filename);
//	}

//	send(new_socket, result, strlen(result), 0);
//}

int main(int argc, char const *argv[]) {
    int sockfd, new_socket;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char command[MAXLINE];
    char arg[MAXLINE];
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
        
    }
    strcpy(path, argv[1]);
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
        
    }// Forcefully attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
        
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

// Forcefully attaching socket to the port 8080
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
        
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    int len = sizeof(cliaddr);
    while (1) {
        if ((new_socket = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t *)&len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        int n = read(new_socket, buffer, MAXLINE);
        buffer[n] = '\0';
        sscanf(buffer, "%s %s", command, arg);
        if (strcmp(command, "search-term") == 0) {
            searchByWord(new_socket, arg);
            } 
	/*else if (strcmp(command, "search-file") == 0) {
                searchByFilename(new_socket, arg);
                }
	*/ else {
                    char message[MAXLINE] = "Invalid command.\n";
                    send(new_socket, message, strlen(message), 0);
                    }
                    close(new_socket);
        
    }
return 0;
}






