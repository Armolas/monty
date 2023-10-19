#include "monty.h"

/**
 * check_func - checks if a function is valid
 * @f: function to check
 * @line: line number in bytecode file
 * @cmd: array of arguments in line <line>
 * @str: line read in line <line>
 * @stream: file descriptor
 * @top: top of the stack
 *
 * Return: Nothing.
 */

void check_func(void (*f)(stack_t **, unsigned int), unsigned int line,
		char **cmd, char *str, FILE *stream, stack_t *top)
{
	if (!f)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd[0]);
		free(str);
		fclose(stream);
		free_list(&top);
		exit(EXIT_FAILURE);
	}
}
