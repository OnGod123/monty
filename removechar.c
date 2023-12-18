#include "monty.h"
#include <ctype.h>  /* Include ctype.h for isspace */

/**
 * removestr - Removes unwanted characters from a string.
 * @str: The input string.
 *
 * Return: A dynamically allocated string with unwanted characters removed.
 *         NULL if the input string is NULL or on memory allocation failure.
 */
char *removestr(const char *str)
{
	int i;
	char *alphabet;
	int skip;
    if (str == NULL)
    {
        printf("The string does not exist\n");
        return NULL;
    }

    alphabet = (char *)malloc(strlen(str) + 1);
    if (alphabet == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

     i = 0;
    skip = 0;

    while (*str)
    {
        if (isspace((unsigned char)*str) || *str == ',' || *str == '$')
        {
            if (!skip)
            {
                alphabet[i++] = ' ';
                skip = 1;
            }
        }
        else
        {
            alphabet[i++] = *str;
            skip = 0;
        }
        str++;
    }

    alphabet[i] = '\0';

    return alphabet;
}

