#include "monty.h"

char *arg = NULL;
/**
 * main - entry point
 * @argc: number of argument
 * @argv: argument vectors
 * Return: 0 or exit failure
 */
int main(int argc, char **argv)
{
	stack_t *top = NULL;
	char *monty, *str = NULL, **cmd;
	unsigned int line = 1;
	size_t ln, nb;
	FILE *stream;
	int ui;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty = argv[1];
	stream = fopen(monty, "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty);
		exit(EXIT_FAILURE);
	}
	ln = getline(&str, &nb, stream);
	ui = ln;
	while (ui != -1)
	{
		if (ln == 1 || is_empty(str) == 0)
		{
			ln = getline(&str, &nb, stream);
			ui = ln;
			line++;
			continue;
		}
		cmd = get_cmd(str, " \n ");
		arg = cmd[1];
		f = get_func(cmd[0]);
		check_func(f, line, cmd, str, stream, top);
		f(&top, line);
		free_args(cmd);
		ln = getline(&str, &nb, stream);
		ui = ln;
		line++;
	}
	free_list(&top);
	free(str);
	fclose(stream);
	return (0);
}
