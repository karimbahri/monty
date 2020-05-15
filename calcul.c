
#include "monty.h"

/**
 * add - sum adds the top two elements of the stack..
 * @stack: pointer to stack.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void add(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->n += tmp->n;
		(*stack)->prev = NULL;
		pop(&tmp, 0);
	}

	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to stack.
 * @line_number: Data for make a push.
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->n -= tmp->n;
		(*stack)->prev = NULL;
		pop(&tmp, 0);
	}

	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - divide the top element of the stack with the second
 * @stack: pointer to stack.
 * @line_number: Data for make a push.
 */

void _mod(stack_t **stack, unsigned int line_number)
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
		(*stack)->n %= tmp->n;
		(*stack)->prev = NULL;
		pop(&tmp, 0);
	}

	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
