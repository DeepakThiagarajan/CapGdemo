#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define MAX_LENGTH 1024
struct file {
    char path[MAX_PATH_LENGTH];
    int index;
    struct file *next;
};

int search_files(char *dir_path, char *search_term, struct file **list) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory '%s'\n", dir_path);
        return EXIT_FAILURE;
    }

    char path[MAX_PATH_LENGTH];
    strncpy(path, dir_path, MAX_PATH_LENGTH);
    strncat(path, "/", MAX_PATH_LENGTH - strlen(path) - 1);

    struct dirent *entry;
    int index = 1;
    while ((entry = readdir(dir)) != NULL) {
        strncat(path, entry->d_name, MAX_PATH_LENGTH - strlen(path) - 1);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            search_files(path, search_term, list);
        }
        else if (entry->d_type == DT_REG) {
            FILE *file = fopen(path, "r");
            if (file == NULL) {
                fprintf(stderr, "Failed to open file '%s'\n", path);
                return EXIT_FAILURE;
            }

            int match_found = 0;
            char line[MAX_LENGTH];
            while (fgets(line, MAX_LENGTH, file) != NULL) {
                if (strstr(line, search_term) != NULL) {
                    match_found = 1;
                    break;
                }
            }

            if (match_found) {
                printf("Match found in file: %s\n", path);
                struct file *new_file = malloc(sizeof(struct file));
                strncpy(new_file->path, path, MAX_PATH_LENGTH);
                new_file->index = index++;
                new_file->next = NULL;
                if (*list == NULL) {
                    *list = new_file;
                } else {
                    struct file *current = *list;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = new_file;
                }
            }

            fclose(file);
        }

        path[strlen(dir_path) + 1] = '\0';
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
