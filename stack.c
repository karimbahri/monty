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

/**
 * mul - multiply the top two elements of the stack..
 * @stack: pointer to stack.
 * @line_number: Data for make a push.
 */

void mul(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->n *= tmp->n;
		(*stack)->prev = NULL;
		pop(&tmp, line_number);
	}

	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divide the top element of the stack with the second
 * @stack: pointer to stack.
 * @line_number: Data for make a push.
 */

void _div(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

	if (*stack && (*stack)->next)
	{
		if (!(*stack)->n)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		*stack = (*stack)->next;
		(*stack)->n /= tmp->n;
		(*stack)->prev = NULL;
		pop(&tmp, line_number);
	}

	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
