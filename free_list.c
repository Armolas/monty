#include "monty.h"
/**
 * free_list - frees a doubly linked list
 * @stack: top of stack
 */
void free_list(stack_t **stack)
{
	stack_t *temp = *stack;

	if (!temp)
		return;
	while (temp)
	{
		*stack = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}
