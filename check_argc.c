#include "monty.h"

/**
 * check_argc - checs the number of args
 * @arg_count: number of argumnets to main
 *
 * Return: Nothing.
 */

void check_argc(int arg_count)
{
	if (arg_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
