#include "monty.h"
/**
 * is_empty - checks if a line is empty
 * @str: line to check
 * Return: 0 for empty else 1
 */
int is_empty(char *str)
{
	char *strcpy = strdup(str);

	if (strtok(strcpy, " \n") == NULL)
	{
		free(strcpy);
		return (0);
	}
	free(strcpy);
	return (1);
}
