#include "monty.h"

/**
* pall - Prints all elements of the stack
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file where pall was called
*
* This function prints all the elements of the stack from top to bottom.
* If the stack is empty, it prints "empty list."
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
