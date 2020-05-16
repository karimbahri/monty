#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
EXTERN;

/**
 * check_instruction - check for instruction
 * @command: given command
 * Return: match fucntion
 */
void (*check_instruction(char *command))(stack_t**, unsigned int)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode)
	{
		if (!strcmp(instructions[i].opcode, command))
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
/**
 * execute_instruction - execute instruction
 * @command: given command
 *@script: the file open
 * @stack: stack
 */
void execute_instruction(char *command, stack_t **stack, FILE *script)
{
	char *ins = strtok(command, " \n\t\r");
	char *arg = strtok(NULL, " \n\t\r");
	void (*function)(stack_t**, unsigned int);
	int number = 0;

	nb_line++;
	if (*command == '\n' || !ins || *ins == '#')
		return;
	if (!strcmp(ins, "push"))
	{
		if (!arg)
		{
			if (*stack)
				free_stack(*stack);
			fclose(script);
			free(command);
			fprintf(stderr, "L%d: usage: push integer\n", nb_line);
			exit(EXIT_FAILURE);
		}
		check_ifInteger(arg);
		number = atoi(arg);
		*stack = push_stack(stack, number);
		return;
	}
	function = check_instruction(ins);
	if (!function)
	{
		if (*stack)
			free_stack(*stack);
		fclose(script);
		fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, ins);
		free(command);
		exit(EXIT_FAILURE);
	}
	function(stack, nb_line);
}
/**
 * check_ifInteger - check if string is integer
 * @number: string to check
 */
void check_ifInteger(char *number)
{
	int i = 1;

	if ((number[0] >= '0' && number[0] <= '9') || number[0] == '-')
	{
		while (number[i])
		{
			if (!(number[i] >= '0' && number[i] <= '9'))
				break;
			i++;
		}
		if (!number[i])
			return;
	}
	fprintf(stderr, "L%d: usage: push integer\n", nb_line);
	exit(EXIT_FAILURE);
}
