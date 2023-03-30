#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "headers.h"

typedef struct struct_File{
    char f_name[MAX_LENGTH];
    char f_path[MAX_PATH_LENGTH];
    struct struct_File* next;
}File;

File *head = NULL;//structure pointer 
File *curr = NULL;//structure pointer
#endif 
