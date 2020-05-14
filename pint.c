#include "monty.h"
/**
 *pint - prints the value at the top of the stack
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
	}
}
