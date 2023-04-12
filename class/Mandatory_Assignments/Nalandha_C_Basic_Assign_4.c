#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_STACK_SIZE 100

void read_file_to_stack(char* file_path, char* stack[], int* stack_size) {
    char line[MAX_LINE_LENGTH + 1]; // +1 for null terminator
    FILE* fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Failed to open file %s", file_path);
        return;
    }

    // Read each line from the file and add it to the stack
    while (fgets(line, MAX_LINE_LENGTH + 1, fp) != NULL && *stack_size < MAX_STACK_SIZE) {
        int line_length = strlen(line);
        if (line[line_length - 1] == '\n') {
            // Remove the newline character if present
            line[line_length - 1] = '\0';
        } else {
            // The line was too long, discard the rest of it
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        // Add the line to the stack if there is room
        if (*stack_size < MAX_STACK_SIZE) {
            stack[*stack_size] = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(stack[*stack_size], line);
            (*stack_size)++;
        }
    }

    fclose(fp);
}

int print_longest_line(char* stack[], int stack_size) {
    int longest_line_length = 0;
    for (int i = 0; i < stack_size; i++) {
        int line_length = strlen(stack[i]);
        if (line_length > longest_line_length) {
            longest_line_length = line_length;
        }
    }

    // Print the longest line and return its length
    for (int i = 0; i < stack_size; i++) {
        if (strlen(stack[i]) == longest_line_length) {
            printf("%s", stack[i]);
        }
    }

    return longest_line_length;
}

int main() {
    char* stack[MAX_STACK_SIZE];
    int stack_size = 0;

    read_file_to_stack("test.txt", stack, &stack_size);
    print_longest_line(stack, stack_size);

    // Free memory allocated for stack
    for (int i = 0; i < stack_size; i++) {
        free(stack[i]);
    }

    return 0;
}
