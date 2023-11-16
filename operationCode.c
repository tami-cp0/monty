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
	int i = 0;
	char *endptr;
	stack_t *new_node;

	while (global_value[i] != '\0')
	{
		if (global_value[i] == '.')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			if (*stack != NULL)
				free_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	data = strtol(global_value, &endptr, 10);
	if (*endptr != '\0' && strcmp(global_value, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*stack != NULL)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*stack != NULL)
			free_stack(stack);
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
	stack_t *temp = *stack;

	(void)line_number;

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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	free(temp);
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecodes file.
 *
 * This function prints the value at the top of the stack.
 * If the stack is empty, it prints an error message and exits.
 *
 * Return: None.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecodes file.
 *
 * This function swaps the top two elements of the stack.
 * If the stack contains fewer than two elements, it prints
 * an error message to stderr and exits with failure status.
 *
 * Return: None.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	current = (*stack)->next;

	temp->prev = current;
	temp->next = current->next;

	current->next = temp;
	current->prev = NULL;

	*stack = current;
}
