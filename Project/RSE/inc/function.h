#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/************************************************************************************
**    HEADERS DECLARED
**
************************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LENGTH 50
#define MAX_FILENAME 20
#define MAX_PATH_LENGTH 1000
#define SEARCH_WITH_WORD 0
#define SEARCH_WITH_FILENAME 1
#define LINE for(int i = 0;i < 100;i++) printf("-");printf("\n");

/************************************************************************************
**    FUNCTION  DECLARATIONS
**
************************************************************************************/

int isFile(const char *);
char *extractFileName(char *);
int createFileNode(char *);
int searchInFile(char *);
int openFile(char *);
int printLinkedList(File **);
int freeMemory(File **);
int allocateMemory();
int searchLocalSystem(const char *);
int searchByWord();
int searchByFilename();
int openWithAbsolutePath();

int search = SEARCH_WITH_FILENAME;//act as a flag to search with filename or word/string in our local system
char filename[MAX_FILENAME];//to take filename
char input[MAX_LENGTH];//to take string or word
char path[MAX_PATH_LENGTH];//Deafult path of user directory

int fileCount = 0;//file increment counter
int counter=0;

typedef struct struct_File{
    char f_name[MAX_LENGTH];
    char f_path[MAX_PATH_LENGTH];
    struct struct_File* next;
}File;

File *head = NULL;//structure pointer 
File *curr = NULL;//structure pointer

#endif 
