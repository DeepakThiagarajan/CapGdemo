#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024
#define LINE printf("---------------------------------------------------------------\n");
#define MAX_LENGTH 256

char path[MAX_LENGTH] = "";
int flag = 1;

void searchByWord() {
    // Code to search for files by word/sentence
}

void searchByFilename() {
    // Code to search for files by filename
}

void openWithAbsolutePath() {
    // Code to open a file with absolute path
}

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAXLINE] = {0};
    char *username = getlogin();
    strcat(path, "/home2/");
    strcat(path, username);
    strcat(path, "/");
    char input[MAXLINE];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    do {
        LINE
        printf("\t\t\tWelcome to Local Search Engine(LSE)\t\n\n");
        LINE
        printf("1. Search by word/sentence\n");
        printf("2. Search by filename\n");
        printf("3. Open file with absolute path\n");
        printf("4. Quit\n");
        LINE
        printf("Choose an option(1-4): ");
        fgets(input, MAXLINE, stdin);
        input[strcspn(input, "\n")] = 0;

        switch (input[0]) {
            case '1':
                printf("\nEnter search term: ");
                fgets(buffer, MAXLINE, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                send(sock, buffer, strlen(buffer), 0);
                valread = read(sock, buffer, MAXLINE);
                printf("\n%s\n\n", buffer);
                break;

            case '2':
                printf("\nEnter file name: ");
                fgets(buffer, MAXLINE, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                send(sock, buffer, strlen(buffer), 0);
                valread = read(sock, buffer, MAXLINE);
                printf("\n%s\n\n", buffer);
                break;

            case '3':
                printf("\nEnter absolute file path: ");
                fgets(buffer, MAXLINE, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                send(sock, buffer, strlen(buffer), 0);
                valread = read(sock, buffer, MAXLINE);
                printf("\n%s\n\n", buffer);
                break;

            case '4':
                flag = 0;
                break;

            default:
                printf("\nInvalid option. Please enter option (1-4).\n");
                break;
        }

        memset(buffer, 0,MAXLINE);
    } while (flag);

    return 0;
}
