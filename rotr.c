#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: points to the top of the stack
 * @line_number: line number in bytecode file
 *
 * Return: Nothing.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;
	(void) line_number;

	if (!(*stack) || (*stack)->next == NULL)
		return;

	while (end->next != NULL)
		end = end->next;
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = end;
}
