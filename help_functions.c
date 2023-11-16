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
		if (*string == '#')
		{
			return (1);
		}
		if (*string == ' ' && *string == '\t')
		{
			return (0);
		}
		string++;
	}
	return (1);
}

/**
 * queue - Sets the data.choice flag to 1 (queue mode)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the source file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data.choice = 1;
}

/**
 * stack_ - Sets the data.choice flag to 0 (stack mode)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the source file
 */
void stack_(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)*stack;

	data.choice = 0;
}
