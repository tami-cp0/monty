#include "monty.h"

/**
 * split_space - Split a string into tokens using spaces and tab as delimiters.
 * @string: The input string to be split.
 *
 * Return: An array of strings (tokens).
 */
char **split_space(char *string)
{
	char **args = NULL;

	int i = 0;

	char *string_cpy, *token = NULL;

	if (string == NULL)
	{
		perror("return value of split_line is NULL");
		exit(EXIT_FAILURE);
	}

	string_cpy = _strdup(string);
	if (string_cpy == NULL)
	{
		perror("split_space: String dup failed");
		exit(EXIT_FAILURE);
	}

	args = malloc(1024 * sizeof(char *));
	if (args == NULL)
	{
		perror("split_space: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(string_cpy, " \t");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("split_space: a token is NULL");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
	free(string_cpy);
	return (args);
}
