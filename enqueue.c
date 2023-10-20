#include "monty.h"
/**
 * enqueue - adds element to end of the list
 * @stack: top of the node
 * @line_number: line number
 */
void enqueue(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp = *stack;

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
	new->next = NULL;
	new->n = atoi(myglob.arg);
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
