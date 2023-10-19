#include "monty.h"
/**
 * pint - prints the top of the stack
 * @stack: top of the stack
 * @line_number: line number of code
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%d: can't pint, empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
