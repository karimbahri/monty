#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push_stack - push stack
 * @stack: stack to push
 * @n: value
 * Return: top of the stack
 */
stack_t *push_stack(stack_t **stack, int n)
{
	stack_t *top;

	top = malloc(sizeof(stack_t));

	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(top);
		exit(EXIT_FAILURE);
	}

	top->n = n;

	top->prev = NULL;
	top->next = *stack;
	if (*stack)
		(*stack)->prev = top;
	*stack = top;

	return (*stack);
}

/**
 * pall - print all the stack
 * @stack: stack to print
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void) line_number;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * free_stack - free stack
 * @stack: stack to free
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			free(stack->prev);
		}
		free(stack);
	}
}
