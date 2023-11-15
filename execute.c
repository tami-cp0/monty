#include "monty.h"

char *global_value = NULL;

/**
 * compute - Process and execute Monty bytecodes from a buffer.
 * @buffer: The buffer containing Monty bytecodes.
 *
 * This function tokenizes Monty bytecodes, validates and executes each
 * instruction, and handles errors during the process. It uses various helper
 * functions such as split_line, split_space, check_number, and check_atoi.
 */
void execute(char *line, stack_t **stack, unsigned int linecount)
{
	unsigned int i = 0;
	unsigned int j;
	char **args = NULL;
    stack_t *temp = NULL;

	instruction_t instructions[] = {
		{"pall", pall},
		{"push", push},
	};

	args = split_space(line);

	for (j = 0; j < sizeof(instructions) / sizeof(instruction_t); j++)
	{ 
        
		if (strcmp(args[0], instructions[j].opcode) == 0)
		{
            if ((strcmp(args[0], "push") == 0) && args[1] == NULL)
            {
		        fprintf(stderr, "L%d: usage: push integer\n", linecount);
                exit(EXIT_FAILURE);
            }
            else if (strcmp(args[0], "push") == 0)
            {
                global_value = _strdup(args[1]);
			    push(stack, linecount);
                if (global_value != NULL)
                    free(global_value);
			    break;
            }
			if (strcmp(args[0], "push") != 0 && strcmp(args[0], instructions[j].opcode) == 0)
        	{
			    instructions[j].f(stack, linecount);
			    return;
        	}
		} 
	}
	if (j == (sizeof(instructions) / sizeof(instruction_t)))
	{
		print_stderr("L");
		fprintf(stderr, "L%d: unknown instruction %s\n", linecount, args[0]);
		exit(EXIT_FAILURE);
	}

}
