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

/**
* pstr - Prints the string from the stack
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
* rotl - Rotates the stack to the top
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	temp->next->next = NULL;
}

/**
* rotr - Rotates the stack to the bottom
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *current = *stack;

	(void)line_number;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		return;
	}

	while (temp->next)
		temp = temp->next;

	temp->prev->next = NULL;
	*stack = temp;
	(*stack)->prev = NULL;
	(*stack)->next = current;
	current->prev = *stack;
}
