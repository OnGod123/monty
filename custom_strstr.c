#include <stddef.h>
/**
 * custom_strstr - Locates the first occurrence of a substring in a string
 * @haystack: The main string to search in
 * @needle: The substring to search for
 *
 * Return: A pointer to the first character of the found substring,
 *         or NULL if the substring is not found.
 */
char *custom_strstr(const char *haystack, const char *needle) {
    while (*haystack) {
        const char *hay = haystack;
        const char *nee = needle;

        
        while (*hay && *nee && *hay == *nee) {
            hay++;
            nee++;
        }

        
        if (!*nee) {
            return (char *)haystack;
        }

        
        haystack++;
    }

    
    return NULL;
}

