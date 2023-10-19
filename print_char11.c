#include "monty.h"

/**
 * pchar - prints the char at the top of a stack
 * @stack: points to the top of the stack
 * @line_number: line number in bytecode file
 *
 * Return: Nothing.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
