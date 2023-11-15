#include "monty.h"

/**
* pop - Removes the top element from the stack.
* @stack: A double pointer to the top of the stack.
* @line_number: The line number of the current operation.
*
* Description: If the stack is empty, prints an error message to stderr
* and exits with a failure status. Otherwise, removes the top element from
* the stack, freeing the memory, and prints the deleted item.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: usage: pop\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	free(temp);
}