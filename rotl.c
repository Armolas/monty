#include "monty.h"
/**
 * rotl - rotates stack to the top
 * @stack: top of the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = *stack, *temp;

	if (!*stack)
		return;
	if (!(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->prev = temp;
	top->next = NULL;
}
