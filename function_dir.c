#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file where the opcode was encountered.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    (*stack)->n *= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

