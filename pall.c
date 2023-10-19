#include "monty.h"
/**
 * pall - prints all eelments of the stack
 * @stack: top of the stack
 * @line_number: line number of code
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
