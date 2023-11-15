#include "monty.h"

/**
* empty_or_space - Check if a string is empty or
* consists of only whitespace characters.
* @string: The input string to be checked.
*
* Return: 1 if the string is empty or contains only whitespace characters,
*         0 otherwise.
*/
int empty_or_space(char *string)
{
	while (*string)
	{
		if (!isspace((unsigned char)*string))

		{
			return (0);
		}
		string++;
	}
	return (1);
}
