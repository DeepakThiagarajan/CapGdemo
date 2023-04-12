#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1000
#define MAX_LINE_LENGTH 10000
#define MAX_TOKENS 100

int num_tokens;
// Function to search for a word using grep command and save the result to file.txt
char * search_for_word(const char *path, const char *word) {
    FILE *output_file;
    char output_filename[MAX_PATH_LENGTH];
    char grep_command[MAX_PATH_LENGTH + 15]; // 15 is the length of "grep -r '' > "
    sprintf(output_filename, "%s/file.txt", path);
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", output_filename);
        exit(1);
    }
    sprintf(grep_command, "find %s -type f -exec grep -l %s {} \\; ", path, word);
    FILE *grep_output = popen(grep_command, "r");
    if (grep_output == NULL) {
        fprintf(stderr, "Error: Could not run grep command\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, grep_output) != NULL) {
        fprintf(output_file, "%s", line);
    }
/*    long int size=ftell(output_file);
	char retu[100]={0,};
	bzero(retu,100);
	if(size>1)
	{
		strcpy(retu,"success");
    		pclose(grep_output);
    		fclose(output_file);
		return retu;
	}
	else
	{
		
		strcpy(retu,"failed");
    		pclose(grep_output);
    		fclose(output_file);
		return retu;
	}
	return retu;
*/
}

char* display_tokens() {
    char line[MAX_LINE_LENGTH];
    FILE *fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.txt\n");
        return;
    }

    // Tokenize the file contents and display the tokens
    char *tokens[MAX_TOKENS];
	num_tokens=0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        tokens[num_tokens++] = strdup(token);
        if (num_tokens == MAX_TOKENS) {
            break;
        }
    }

    fclose(fp);
	char out[20];
	
	bzero(line,MAX_LINE_LENGTH);
	strcpy(line,"Found ");
	sprintf(out,"%d",num_tokens);
	strcat(line,out);
	strcat(line," files with the word\n");

    // Display the tokens
    for (int i = 0; i < num_tokens; i++) {
	bzero(out,20);
	sprintf(out,"%d",i+1);
	strcat(line,out);
	strcat(line,". ");
	strcat(line,tokens[i]);
	strcat(line,"\n");
    }
return line;
}

char *displ2(char choice[102])
{

    // Prompt the user to select a file to display its contents
    int choice1=atoi(choice);
 //   printf("Enter the number of the file to display its contents (0 to exit): ");
   // scanf("%d", &choice);

    char *tokens[MAX_TOKENS];
	num_tokens=0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        tokens[num_tokens++] = strdup(token);
        if (num_tokens == MAX_TOKENS) {
            break;
        }
    }
	char *line1;
    if (choice1 >= 0 && choice1 <= num_tokens) {
        FILE *file = fopen(tokens[choice], "r");
        if (file == NULL) {
            strcpy(line1,"Error opening file: ");
		strcat(line1,tokens[choice]);
		strcat(line1,"\n");
        } else {
		strcpy(line1,"Contents of file: ");
		strcat(line1, tokens[choice]);
		strcat(line1,"\n\n");
            while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                strcat(line1, line);
            }
            fclose(file);
        }
    }
	return line1;
}
// Function to recursively search for directories and files
void search(const char *path, const char *word) {
    
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    // Iterate over all entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively search the subdirectory
            search(full_path, word);
        } else if (entry->d_type == DT_REG) {
            // Search the file for the word
            search_for_word(path, word);
        }
    }

    closedir(dir);
}

int main() {
    char path[MAX_PATH_LENGTH];
    char word[MAX_LINE_LENGTH];

    // Prompt the user for the path and word to search
    printf("Enter the path to search: ");
    fgets(path, MAX_PATH_LENGTH, stdin);
    path[strcspn(path, "\n")] = '\0';

    printf("Enter the word to search: ");
    fgets(word, MAX_LINE_LENGTH, stdin);
    word[strcspn(word, "\n")] = '\0';

    // Call the recursive search function
    search(path, word);

    // Display the tokens
    display_tokens();

    return 0;
    

}



