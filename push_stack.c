#include "monty.h"

/**
 * push - Pushes a new node with the given data onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the source file where push was called
 *
 * This function creates a new node with the specified data and adds it to the
 * top of the stack.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int data;

	stack_t *new_node;

	data = atoi(global_value);
	if (data == 0 && strcmp(global_value, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
