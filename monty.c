#include "monty.h"

/**
* main - Entry point of the program
* @argc: The number of command-line arguments
* @argv: An array of strings containing the command-line arguments
*
* Return: Always 0 (success)
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	stack_t *stack = NULL;
	unsigned int linecount = 1;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * 1024);

	while (fgets(line, 1024, file) != NULL)
	{
		if (empty_or_space(line) == 1)
		{
			linecount++;
			continue;
		}
		else
		{
			line[strcspn(line, "\n")] = '\0';
			execute(line, &stack, linecount);
			linecount++;
		}

	}
	free(line);
	free_stack(&stack);
	fclose(file);
	return (0);
}
