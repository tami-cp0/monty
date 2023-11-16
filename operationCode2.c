#include "monty.h"

/**
* add - Adds the top two elements of the stack
* @stack: Double pointer to the head of the stack
* @linecount: Line number in the source file
*
* This function adds the top two elements of the stack and replaces them
* with the result. If the stack contains less than two elements, it prints
* an error message and exits with EXIT_FAILURE.
*
* Return: void
*/
void add(stack_t **stack, unsigned int linecount)
{
	int result;

	stack_t *temp = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linecount);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}
