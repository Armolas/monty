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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
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
