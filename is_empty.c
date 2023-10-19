#include "monty.h"
/**
 * is_empty - checks if a line is empty
 * @str: line to check
 * Return: 0 for empty else 1
 */
int is_empty(char *str)
{
	char *strcpy = strdup(str), *strcpy2 = strdup(str);
	char *comment;

	comment = strtok(strcpy2, " \n");
	if (strtok(strcpy, " \n") == NULL || comment[0] == '#')
	{
		free(strcpy);
		free(strcpy2);
		return (0);
	}
	free(strcpy2);
	free(strcpy);
	return (1);
}
