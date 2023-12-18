#include "monty.h"

/**
 * opcode_struct - Array of Monty bytecode instructions and their functions.
 * @opcode: The Monty bytecode instruction.
 * @f: The corresponding function for the instruction.
 */
instruction_t opcode_struct[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"swap", swap},
    {"nop", nop},
    {"mul", mul},
    {"div", custom_div},
    {"sub", sub},
    {"add", add},
    {NULL, NULL}
};

/**
 * head - Global pointer to the top of the stack.
 */
stack_t *head = NULL;

/**
 * execute_func - Execute a Monty bytecode instruction.
 * @string: The Monty bytecode instruction.
 *
 * This function searches for a matching opcode in the opcode_struct array
 * and calls the corresponding function with the given argument.
 * If the opcode is not found, it prints an error message and exits.
 */
void execute_func(const char *string)
{
    int arg, i = 0;

    arg = atoi_custom(string);

    while (opcode_struct[i].opcode != NULL)
    {
        if (strcmp(opcode_struct[i].opcode, string) == 0)
        {
            opcode_struct[i].f(&head, arg);
            return;
        }
        i++;
    }

    fprintf(stderr, "Error: Unknown opcode %s\n", string);
    exit(EXIT_FAILURE);
}

