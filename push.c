#include "monty.h"
/**
 * push - pushes to the top of the stack
 * @stack: top of the stack
 * @line_number: line number of code
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!arg)
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = atoi(arg);
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
