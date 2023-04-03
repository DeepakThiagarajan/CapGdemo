#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256
#define MAX_LENGTH 1024

int search_files(char *dir_path, char *search_term) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory '%s'\n", dir_path);
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            search_files(path, search_term);
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
            }

            fclose(file);
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}

