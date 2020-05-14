
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
