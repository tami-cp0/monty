#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LINE_SIZE 10240
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

/**
 * struct global - Structure to hold global data for the Mini Monty interpreter
 * @value: A string representing the numeric value extracted from user input
 * @choice: An integer indicating the current mode (0 for stack, 1 for queue)
 */
typedef struct global
{
	char *value;
	int choice;
} global;

extern global data;

/* Define the function prototypes for each operation code */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* main funcitons */
void execute(char *line, stack_t **stack, unsigned int linecount);

/* memory functions */
char *_strdup(char *str);
void free_mem(char **args);
void free_stack(stack_t **stack);

/* helper functions */
int empty_or_space(char *string);
void queue(stack_t **stack, unsigned int line_number);
void stack_(stack_t **stack, unsigned int line_number);
char **split_space(char *string);

#endif /* MONTY_H */
