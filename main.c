#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - main function
 * @argc: size of argv
 * @argv: args
 * Return: 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *script = NULL;
	char *instruction = NULL;
	size_t del = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");

	if (!script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&instruction, &del, script) != -1)
	{
		/*printf("%s\n", instruction);*/
		execute_instruction(instruction, &stack, script);
		free(instruction);
		instruction = NULL;
	}
	free(instruction);
	free_stack(stack);
	fclose(script);

	return (EXIT_SUCCESS);
}
