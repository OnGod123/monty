#include "monty.h"
char *removestr(const char *str) {
	char *alphabet;
	int i;
    if (str == NULL) {
        printf("The string does not exist\n");
        return NULL;
    }

    
    alphabet = (char *)malloc(strlen(str) + 1);
    if (alphabet == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    	
	i = 0;

    while (*str == ' ') {
        str++;
    }

    while (*str) {
        
        if (*str != '$' && *str != '\t' && *str != ' ' && *str != '\0' && *str != ',') {
            alphabet[i++] = *str;
        }
        str++;
    }

    alphabet[i] = '\0';

    return alphabet;
}
