#include "monty.h"
/**
 * pstr - prints the char at the top of stack
 * @stack: top of stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		printf("\n");
		return;
	}
	while (temp)
	{
		if (temp->n < 1 || temp->n > 127)
		{
			break;
		}
		write(1, &temp->n, 1);
		temp = temp->next;
	}
	printf("\n");
}
