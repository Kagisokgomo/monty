#include "monty.h"

stack_t *stack = NULL;  // Global stack pointer

/**
 * main - Entry point for the Monty Bytecode Interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    process_file(argv[1]);

    free_stack(stack);

    return (EXIT_SUCCESS);
}
