#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern char *arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

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
		char **cmd, char *str, FILE *stream, stack_t *top);
void (*get_func(char *cmd))(stack_t **, unsigned int);
void check_argc(int arg_count);
void check_stream(FILE *stream, char *monty);

char **get_cmd(char *, char *);
int are_digits(char *str);
void pstr(stack_t **stack, unsigned int line_number);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_2(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void free_list(stack_t **);
void free_args(char **);
int is_empty(char *);

#endif
