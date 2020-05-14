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
 * @stack: stack
 */
void execute_instruction(char *command, stack_t **stack, FILE *script)
{
	char *ins = strtok(command, " \n\t\r");
	char *arg = strtok(NULL, " \n\t\r");
	void (*function)(stack_t**, unsigned int);
	int number = 0;

	nb_line++;
	if (*command == '\n' || !ins)
		return;
	if (!strncmp(ins, "push", 4))
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
		free(command);
		fclose(script);
		fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, ins);
		exit(EXIT_FAILURE);
	}

	function(stack, 2);
}

/**
 * check_ifInteger - check if string is integer
 * @number: string to check
 */
void check_ifInteger(char *number)
{
	int i = 0;

	if ((number[0] >= '0' && number[0] <= '9') || number[0] == '-')
	{
		while (number[i] && number[i] != '\n')
		{
			if (!(number[i] >= '0' && number[i] <= '9'))
				break;
			i++;
		}
		if (!number[i] || number[i] == '\n')
			return;
	}


	fprintf(stderr, "L%d: usage: push integer\n", nb_line);
	exit(EXIT_FAILURE);
}
