#include "monty.h"
/**
 * get_func - gets the function
 * @cmd: command
 * Return: pointer to function
 */
void (*get_func(char *cmd))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint}, {"pchar", pchar},
		{"pop", pop}, {"mod", mod},
		{"swap", swap}, {"mul", mul},
		{"add", add}, {"div", div_2},
		{"nop", nop}, {"sub",  sub},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(cmd, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
