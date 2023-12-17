#include "monty.h"
#include "stddef.h"
/**
 * strtok_custom - Custom implementation of strtok function.
 * @str: The string to tokenize.
 * @delim: The delimiter character.
 *
 * Return: A pointer to the next token found in the string, or NULL if no more tokens.
 */
char *strtok_custom(char *str, char delim) {
	static char *current;
	char *start;	
	 current = NULL;


    	if (str != NULL) {
        	current = str;
   	 }

    	if (current == NULL || *current == '\0') {
        	return NULL;
    	}

    	start = current;

   
    	while (*current != '\0' && *current != delim) {
        	current++;
    	}

   
    	if (*current != '\0') {
        	*current = '\0';
        	current++;
    	}

    	return start;
}
