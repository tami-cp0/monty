#include "monty.h"

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
