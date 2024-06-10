#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack (top)
 * @line_number: Line number in the file
 * @arg: Argument to push
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int value;
    stack_t *new_node;

    if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-' && !isdigit(arg[1])))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Double pointer to the stack (top)
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack (top)
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;

    while (current != NULL)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
}
