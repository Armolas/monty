#include "monty.h"

/**
 * nop - does nothing
 * @stack: points to the head of the stack
 * @line_number: line number in bytecode file
 *
 * Return: We came to do nothing and we will return
 * with nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
