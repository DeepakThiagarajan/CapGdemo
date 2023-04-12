#include <stdio.h>
#include <string.h>
#include <dirent.h>

void search_files(const char *dir_path, const char *search_term) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'\n", dir_path);
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char subdir_path[1024];
            sprintf(subdir_path, "%s/%s", dir_path, entry->d_name);
            search_files(subdir_path, search_term);
        } else {
            char file_path[1024];
            sprintf(file_path, "%s/%s", dir_path, entry->d_name);
            FILE *file = fopen(file_path, "r");
            if (file == NULL) {
                continue;
            }
            char line[1024];
            int line_num = 1;
            while (fgets(line, sizeof(line), file)) {
                if (strstr(line, search_term) != NULL) {
                    printf("%s:%d\n", file_path, line_num);
                }
                line_num++;
            }
            fclose(file);
        }
    }
    closedir(dir);
}

int main() {
    char dir_path[1024];
    printf("Enter directory path: ");
    scanf("%s", dir_path);
    char search_term[1024];
    printf("Enter search term: ");
    scanf("%s", search_term);
    search_files(dir_path, search_term);
    char file_path[1024];
    printf("Enter file path to open: ");
    scanf("%s", file_path);
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", file_path);
        return 1;
    }
    char line[1024];
    int line_num = 1;
    printf("Contents of file '%s':\n", file_path);
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_num, line);
        line_num++;
    }
    fclose(file);
    return 0;
}
