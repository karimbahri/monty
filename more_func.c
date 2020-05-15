#include "monty.h"

/**
 *swap-swaps the top two elements of the stack.
 *
 * @stack: first element of a double linked list.
 * @line_number: lenght of the list.
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
int num;
(void)line_number;

	if (*stack && (*stack)->next)
	{
		num = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = num;

	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}

/**
 * nop - The opcode nop doesn’t do anything.
 *
 * @stack: first element of a double linked list.
 * @line_number: lenght of the list.
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
