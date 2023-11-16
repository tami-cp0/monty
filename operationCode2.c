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

/**
* nop - Does nothing (no operation)
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*
* Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* sub - Subtracts the top two elements of the stack
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*
* Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}

/**
* my_div - Divides the second top element by the top element
* @stack: Double pointer to the head of the stack
* @line_number: Line number in the source file
*
* Return: Void
*/
void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n / (*stack)->n);
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the source file
 *
 * Return: Void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->n * (*stack)->next->n);
	temp = *stack;
	*stack = *stack->next;
	*stack->n = result;
	free(temp);
}
