#include "monty.h"

/**
* mod - Computes the modulo of the second top element by the top element
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*
* Return: Void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n % (*stack)->n);
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}

/**
* pchar - Prints the character at the top of the stack
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*
* Return: Void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->n < 0 || (*stack)->n > 127) && !isprint((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
