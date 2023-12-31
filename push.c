#include "monty.h"

/**
 * push - pushes to the top of the stack
 * @stack: top of the stack
 * @line_number: line number of code
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!myglob.arg)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (are_digits(myglob.arg) == 1)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = atoi(myglob.arg);
	if (!*stack)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}
