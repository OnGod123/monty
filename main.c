#include "monty.h"

/**
 * main - Entry point of the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
    char *input2;
    char *input;
    int i, length;
    char *token;
    char **ptr_string;
    

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Read file content into a string */
    input = readFileToString(argv[1]);

    /* Remove unwanted characters from the string */
    input2 = removestr(input);

    /* Get the length of the modified string */
    length = strlen(input2);

    /* Dynamic array to store pointers to tokens */
    ptr_string = malloc(length * sizeof(char *));
    if (ptr_string == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    i = 0;

    /* Using the custom strtok function */
    token = strtok_custom(input2, '\n');
    while (token != NULL && i < length)
    {
        ptr_string[i++] = token;
        execute_func(token);
        token = strtok_custom(NULL, '\n');
    }

    /* Do something with the ptr_string array */

    /* Don't forget to free the dynamically allocated memory */
    free(ptr_string);
    free(input);
    free(input2);

    return 0;
}

