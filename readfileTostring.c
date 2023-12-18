#include <stdio.h>
#include <stdlib.h>

/**
 * readFileToString - Reads the contents of a file into a string.
 * @file_name: The name of the file to read.
 *
 * Return: A dynamically allocated string containing the file contents.
 *         NULL on failure.
 */
char *readFileToString(const char *file_name) {
    long file_size;
    char *content;
    FILE *file;

    file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    content = (char *)malloc(file_size + 1);  
    if (content == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0'; 

    fclose(file);
    return content;
}

