#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the file.
 *
 * Description: The push function adds a new node to the top of the stack.
 * If line_number is zero, it prints an error message and exits with FAILURE.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
    if (line_number == 0)
    {
        fprintf(stderr, "Error: Line number cannot be zero\n");
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = 0;  
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the opcode being executed.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE); 
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(temp);
}

/**
 * _pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the head of the stack.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    	stack_t *current;
	current	= *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
