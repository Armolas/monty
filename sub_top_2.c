#include "monty.h"

/**
 * sub - subtract the first element of the stack from the second
 * element
 * @stack: points to the top of the stack
 * @line_number: the line number in bytecode file
 *
 * Return: NOthing.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *sub_node = malloc(sizeof(stack_t));
	size_t i = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub_node->n = (*stack)->next->n - (*stack)->n;
	for (i = 0; i < 2; i++)
		pop(stack, line_number);

	sub_node->next = *stack;
	sub_node->prev = NULL;
	*stack = sub_node;
}
