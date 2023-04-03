#include <utility.h>

int csfd = -1;
int sfd = -1;

void signalHandler(int sig)
{
    printf("Recieved Signal %d\n", sig);
    close(sfd);
    close(csfd);
    exit(sig);
}
void exitfunc()
{
    close(sfd);
}



int main()
{
//    signal(SIGINT, signalHandler);
    struct sockaddr_in server, client;
    int retval = -1;
    int ret = -1;
    socklen_t len;
    pid_t childpid;
    char buf[MAX];
    char addr[MAX];
    char choice_buf[2];
    char rec_path[MAX];
    char user_path[MAX];
    int num;


    sfd = socket(AF_INET, SOCK_STREAM, 0);

    // If socket is not created then an error message will be printed.

    if (-1 == sfd)
    {
        perror("\nSERVER: SOCKET ERROR!!!\n");
        return FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(MYPORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.2");


    // Binding the socket to the address.

    retval = bind(sfd, (struct sockaddr *)&server, sizeof(server));

    // If there is an error while binding an error message is displayed and socket will be closed.
    if (-1 == retval)
    {
        perror("\nSERVER: BINDING ERROR!!!\n");
        return FAILURE;
    }

    // Listening for connections.

    retval = listen(sfd, 5);

    // If there is an error while listening for connections an error message is displayed and socket will be closed.

    if (-1 == retval)
    {
        perror("\nSERVER: LISTEN ERROR!!! \n");
        return FAILURE;
    }

    for (;;)
    {
        printf("\n ....WAITING FOR CLIENT....\n");
        memset(&client, 0, sizeof(client));
        len = sizeof(client);

        // Accepting a client connection.

        csfd = accept(sfd, (struct sockaddr *)&client, &len);

        // If there is an error while accepting a connection an error message will be printed.

        if (-1 == csfd)
        {
            perror("\nSERVER: CONNECTION ERROR!!!\n");
            return FAILURE;
        }
        if ((childpid = fork()) == 0)
        {
            printf("\n CONNECTION FROM : %s\n", inet_ntop(AF_INET, &client.sin_addr, addr, sizeof(addr)));
            recv(csfd, rec_path, sizeof(rec_path), 0);
            DIR *dir = opendir(rec_path);
            if (dir)
            {
                printf("The received path is :%s\n", rec_path);
                strcpy(user_path, rec_path);
            }
            else
            {
                // strncpy(choice_buf, rec_path, 2);
                perror("SERVER : Error Opening Directory\n");
                close(csfd);
                exit(SUCCESS);
            }
            for (;;)
            {

                ret = recv(csfd, choice_buf, sizeof(choice_buf), 0);
                if (FAILURE == ret)
                {
                    perror("\nSERVER: FAILURE IN READING!!!\n");
                    return FAILURE;
                }

                printf("Recv option: %s\n", choice_buf);
                char choice = choice_buf[0];
                char filenum[5], file_contents[BUFSIZ];
                switch (choice)
                {
                case '1':
                    memset(buf, 0, sizeof(buf));
                    ret = read_data(csfd, buf);
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN READING SEARCH STRING!!!\n");
                        // return FAILURE;
                    }

                    system("rm files.txt");
                    system("touch files.txt");
                    int fd = open("files.txt", O_RDWR, 0644);
                    printf("Search string is %s\n", buf);
                    printf("The received path is :%s\n", user_path);
                    int ret = list_files_recursively(fd, user_path, buf);
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN GETTING FILES!!!\n");
                        continue;
                        // return FAILURE;
                    }

                    strcpy(buf, read_contents(buf, "files.txt"));
                    if (strlen(buf) < 5)
                    {
                        send(csfd, "-1", strlen("-1"), 0);
                        bzero(choice_buf, sizeof(choice_buf));
                        continue;
                    }
                    ret = send(csfd, buf, strlen(buf), 0);
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN WRITING FILE NAMES!!!\n");
                        bzero(choice_buf, sizeof(choice_buf));
                        // return FAILURE;
                    }
                    ret = recv(csfd, &filenum, sizeof(filenum), 0);
                    if (filenum[0] == '0')
                    {
                        printf("Denied reading file content from client\n");
                        bzero(choice_buf, sizeof(choice_buf));
                        continue;
                    }
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN READING FILE NUMBER!!!\n");
                        bzero(choice_buf, sizeof(choice_buf));
                        continue;
                        // return FAILURE;
                    }
                    printf("\nRecieved file number: %s\n", filenum);
                    num = atoi(filenum);
                    strcpy(file_contents, read_file_contents(file_contents, num - 1));
                    ret = send(csfd, file_contents, strlen(file_contents), 0);
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN WRITING FILE CONTENTS!!!\n");
                        // return FAILURE;
                    }
                    fflush(NULL);
                    bzero(buf, sizeof(buf));
                    bzero(filenum, sizeof(filenum));
                    bzero(file_contents, sizeof(file_contents));
                    bzero(choice_buf, sizeof(choice_buf));
                    break;

                case '2':
                    ret = read_data(csfd, buf);
                    if (FAILURE == ret)
                    {
                        perror("\nSERVER: FAILURE IN READING FILE NAME(PATH)!!!\n");
                        // return FAILURE;
                    }
                    // buf[strlen(buf)]='\0';
                    printf("File name is %s", buf);
                    FILE *fpt = fopen(buf, "r");
                    if (fpt)
                    {
                        fclose(fpt);
                        strcpy(file_contents, read_contents(file_contents, buf));
                        // printf("%s", file_contents);
                        file_contents[strlen(file_contents)] = '\0';
                        ret = send(csfd, file_contents, strlen(file_contents), 0);
                        if (FAILURE == ret)
                        {
                            perror("\nSERVER: FAILURE IN WRITING FILE CONTENTS!!!\n");
                            // return FAILURE;
                        }
                    }
                    else
                    {
                        send(csfd, "File Not Found", strlen("File Not Found"), 0);
                    }
                    fflush(NULL);
                    bzero(buf, sizeof(buf));
                    bzero(file_contents, sizeof(file_contents));
                    bzero(choice_buf, sizeof(choice_buf));
                    break;
                case '3':
                    close(csfd);
                    exit(SUCCESS);
                default:
                    printf("Enter valid option\n");
                }
            }
            close(csfd);
        }
    }
    close(sfd);
    return SUCCESS;
}
