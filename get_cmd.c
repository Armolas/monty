#include "monty.h"
/**
 * get_cmd - get the command and tokenize it
 * @linebuf: string from line
 * @delim: delimiter
 * Return: array of command and argument
 */
char **get_cmd(char *linebuf, char *delim)
{
	int i = 0;
	char **args;
	char *arg;
	char *bufcpy = strdup(linebuf);

	args = malloc(sizeof(char *) * 2);
	arg = strtok(bufcpy, delim);
	while (arg)
	{
		args[i] = strdup(arg);
		arg = strtok(NULL, delim);
		i++;
	}
	if (i < 2)
		args[i] = NULL;
	free(bufcpy);
	return (args);
}
