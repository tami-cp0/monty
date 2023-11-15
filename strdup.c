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

