#include "monty.h"

/**
 *pint- prints the value at the top of the stack
 *@stack: stack to print
 *@line_number: line number
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 *pop - removes the top element of the stack.
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

		if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
	{
		free_stack(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		tmp->next->prev = NULL;
	}
	free(tmp);
}
