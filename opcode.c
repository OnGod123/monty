#include "monty.h"

/**
 * execute_func - Execute a Monty bytecode instruction
 * @string: The Monty bytecode instruction
 *
 * This function interprets a Monty bytecode instruction, converts the
 * arguments to integers, and calls the corresponding function.
 */


instruction_t opcode_struct[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"swap", swap},
    {"nop", nop},
    {"mul", mul},
    {"div",custom_div},
    {"sub", sub},
    {"add", add},
    {NULL, NULL}
};

stack_t *head = NULL;
void execute_func(const char *string)
{
    int arg, i = 0;
    instruction_t opcode_struct[8];
    char *true_1;
    arg = atoi_custom(string);

  while (opcode_struct[i].opcode != NULL)
    {
        if ((true_1 = strstr(opcode_struct[i].opcode, string)))
        {
            opcode_struct[i].f(&head, arg);
            return;
        }
        i++;
    }
}

