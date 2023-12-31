#include "monty.h"

void execute(char *line, stack_t **stack, unsigned int linecount);
global data;

/**
 * execute - Executes the given instruction based on the input line
 * @line: The input line containing the instruction
 * @stack: Double pointer to the head of the stack
 * @linecount: Line number in the source file
 *
 * This function parses the input line,
 * identifies the instruction, and executes
 * the corresponding function.
 * If an unknown instruction is encountered, it exits with an error message.
 *
 * Return: void
 */
void execute(char *line, stack_t **stack, unsigned int linecount)
{
	unsigned int j;
	char **args = NULL;

	instruction_t instructions[] = {
		{"pall", pall}, {"push", push}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", my_div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"queue", queue}, {"stack", stack_},
	};

	args = split_space(line);

	for (j = 0; j < sizeof(instructions) / sizeof(instruction_t); j++)
	{
		if (strcmp(args[0], "#") == 0)
			return;

		if (strcmp(args[0], instructions[j].opcode) == 0)
		{
			if ((strcmp(args[0], "push") == 0) && args[1] == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", linecount);
				free_mem(args), exit(EXIT_FAILURE);
			}
			else if (strcmp(args[0], "push") == 0)
			{
				data.value = _strdup(args[1]);
				push(stack, linecount);
				if (data.value != NULL)
					free(data.value);
				free_mem(args);
				break;
			}

			if (strcmp(args[0], "push") != 0)
			{
				if (strcmp(args[0], instructions[j].opcode) == 0)
				{
					instructions[j].f(stack, linecount);
					free_mem(args);
					return;
				}
			}
		}
	}
	if (j == (sizeof(instructions) / sizeof(instruction_t)))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linecount, args[0]);
		free_mem(args), exit(EXIT_FAILURE);
	}
}
