#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define MAX 1024

int searchWord(const char*,const char*);

typedef struct struct_file
{
	char f_path[MAX];
	struct struct_file *next;
}File;
File *head;
File *curr;
int counter = 0;

int main()
{
	char path[MAX];
	char word[MAX];
	char * username = getlogin();
	strcat(path, "/home2/");
    	strcat(path, username);
    	strcat(path, "/");;
  	printf("\nEnter word to search: \n");
	scanf("%s", word);
        searchWord(path,word);
    
                
               

    return(EXIT_SUCCESS);
}


int searchWord(const char * path, const char *word)
{
    
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(strcmp(dir->d_name, ".") == 0 ||
                 strcmp(dir->d_name, "..") == 0 ||
                    dir->d_name[0] == '.'){
                continue;
            }
            char *currPath = (char *) calloc(1000, sizeof(char));
            strcat(currPath, path);
            strcat(currPath, dir->d_name);
            strcat(currPath, "/");
            if(d == 0){
                searchWord(currPath,word); // Recursive call to the new appended path
            }else{
                if(strstr(dir->d_name,".txt")==NULL
                            &&strstr(dir->d_name,".c")==NULL   
                                &&strstr(dir->d_name,".h")==NULL)
                {
                    free(currPath);
                    continue;
                }
                currPath[strlen(currPath) - 1] = '\0';
                    // int res = searchInFile(currPath);
                    // if(res == EXIT_FAILURE){
                    //     free(currPath);
                    //     return EXIT_FAILURE;
    
                FILE *f = fopen(currPath, "r");
                if( access( currPath, F_OK ) != 0) {
        //File doesn't have read permission
                    return EXIT_FAILURE;
                }
                if(f == NULL){
                    return EXIT_FAILURE;
                }
                char temp[MAX];
                while (fgets(temp, MAX, f) != NULL)
                {
                    if(strstr(temp, word) != NULL){ //Match found
                    // fileCount++;
                    // int res = createFileNode(path);
                    // if(res == EXIT_FAILURE){
                    // return EXIT_FAILURE;
                    // char copyPath[MAX_PATH_LENGTH];
                    // strcpy(copyPath, path);

                    if(head == NULL){
                    head = (File *) malloc(sizeof(File));
                    if(head==NULL)
                    {
                    fprintf(stderr,"%s","Memory Allocation Failed...!!\n");
                    return EXIT_FAILURE;
                    }
                    strcpy(head->f_path, path);
                    // char * str = extractFileName(path);
                    // strcpy(head->f_name, str);
                    counter=0;
                    printf("File %d -->path:[%s]\n",counter, head->f_path);
                    // free(str); 
                    head->next = NULL;
                    curr = head;       
                }else{
                    curr->next = (File *) malloc(sizeof(File));
                    if(curr->next==NULL)
                    {
                        fprintf(stderr,"%s","Memory Allocation Failed...!!\n");
                        return EXIT_FAILURE;
                    }
                    curr = curr->next;
                    strcpy(curr->f_path, path);
                    // char * str = extractFileName(path);
                    // strcpy(curr->f_name, str);
                    counter+=1;
                    printf("File %d -->path:[%s]\n",counter, curr->f_path);
                    // free(str);
                    curr->next = NULL;
                }
                
                break;
                }
            }   
            if(f){
                    fclose(f);
                }
             }
                        
                free(currPath);
            }
        closedir(d);
    }
    else   { 
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
