#include "monty.h"

/**
 * swap - swaps the first two elements of a stack
 * @stack: the top of the stack
 * @line_number: the line number of the command
 *
 * Return: Nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int num = (*stack)->n;

	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
