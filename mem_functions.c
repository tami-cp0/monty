#include "monty.h"

/**
* _strdup -   returns a pointer to a newly allocated space in memory
* which contains a copy of the string given as a parameter.
*
* @str: string input
* Return: a pointer to a newly allocated space in memory
*/
char *_strdup(char *str)
{

	int length = strlen(str);

	char *ptr = malloc(length + 1);

	if (ptr == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	strcpy(ptr, str);
	return (ptr);
}

/**
* free_mem - functions that frees double pointers
* @args: double pointer to be freed
* Return: void
*/
void free_mem(char **args)
{
	int i;

	if (args == NULL)
		return;
	for (i = 0; args[i]; i++)
	{
		if (args[i] != NULL)
		{
			free(args[i]);
		}
	}
	if (args != NULL)
		free(args);
}
