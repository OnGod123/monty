#include "monty.h"
/**
 * atoi_custom - Converts a string to an integer
 * @str: The input string
 *
 * Return: The converted integer, or 0 if an error occurs
 */
int atoi_custom(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
    {
        str++;
    }

    /** Handle optional sign **/
    if (*str == '-' || *str == '+')
    {
        sign = (*str++ == '-') ? -1 : 1;
    }

    /** Convert digits to integer **/
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str++ - '0');
    }

    return sign * result;
}

