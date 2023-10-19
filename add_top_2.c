#include "monty.h"

/**
 * add - adds the first two elements of a stack
 * @stack: points to the top of the stack
 * @line_number: the line number in bytecode file
 *
 * Return: NOthing.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *add_node = malloc(sizeof(stack_t));
	size_t i = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	add_node->n = (*stack)->n + (*stack)->next->n;
	for (i = 0; i < 2; i++)
		pop(stack, line_number);

	add_node->next = *stack;
	add_node->prev = NULL;
	*stack = add_node;
}
