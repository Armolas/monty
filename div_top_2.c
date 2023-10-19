#include "monty.h"

/**
 * div_2 - divides the second top element by the first
 * element on the stack
 * @stack: points to the top of the stack
 * @line_number: the line number in bytecode file
 *
 * Return: NOthing.
 */

void div_2(stack_t **stack, unsigned int line_number)
{
	stack_t *div_node = malloc(sizeof(stack_t));
	size_t i = 0;

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	div_node->n = (*stack)->next->n / (*stack)->n;
	for (i = 0; i < 2; i++)
		pop(stack, line_number);

	div_node->next = *stack;
	div_node->prev = NULL;
	*stack = div_node;
}

/**
 * mul - multiplies the second top element by the first
 * element on the stack
 * @stack: points to the top of the stack
 * @line_number: the line number in bytecode file
 *
 * Return: NOthing.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *mul_node = malloc(sizeof(stack_t));
	size_t i = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul_node->n = (*stack)->next->n * (*stack)->n;
	for (i = 0; i < 2; i++)
		pop(stack, line_number);

	mul_node->next = *stack;
	mul_node->prev = NULL;
	*stack = mul_node;
}

/**
 * mod - computes the rest of the division of the second top
 * element by the first element on the stack
 * @stack: points to the top of the stack
 * @line_number: the line number in bytecode file
 *
 * Return: NOthing.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *mod_node = malloc(sizeof(stack_t));
	size_t i = 0;

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod_node->n = (*stack)->next->n % (*stack)->n;
	for (i = 0; i < 2; i++)
		pop(stack, line_number);

	mod_node->next = *stack;
	mod_node->prev = NULL;
	*stack = mod_node;
}
