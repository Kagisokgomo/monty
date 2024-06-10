#include "monty.h"

/**
 * execute_line - Executes a single line of bytecode
 * @line: Line of bytecode
 * @line_number: Line number in the file
 * @stack: Double pointer to the stack (top)
 */
void execute_line(char *line, unsigned int line_number, stack_t **stack)
{
    char *opcode;
    char *arg;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint}, // Add pint to the instructions set
        {NULL, NULL}
    };
    int i;

    opcode = strtok(line, " \n\t");
    if (opcode == NULL || opcode[0] == '#')
        return;  // Ignore empty lines and comments

    arg = strtok(NULL, " \n\t");

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
            {
                instructions[i].f(stack, line_number, arg);
            }
            else
            {
                instructions[i].f(stack, line_number);
            }
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * process_file - Reads and processes a Monty bytecode file
 * @filename: Name of the file to process
 */
void process_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        execute_line(line, line_number, &stack);
    }

    free(line);
    fclose(file);
}
