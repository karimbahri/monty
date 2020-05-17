#include "monty.h"

/**
 *pstr -prints the string starting at the top of the stack
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		putchar('\n');
		return;
	}

	else
	{
		while (tmp)
		{
			if (tmp->n > 127 || tmp->n <= 0)
				break;

			putchar(tmp->n);
			tmp = tmp->next;
		}

		putchar('\n');
	}

}
/**
 *rotl -rotates the stack to the top.
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

	if (!stack || !*stack)
		return;

	while (tmp->next)
	{
		swap(&tmp, line_number);
		tmp = tmp->next;
	}

}

/**
 *rotr -rotates the stack to the bottom.
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *last = *stack, *tmp = NULL;
(void)line_number;

	if (!stack || !*stack)
		return;

	while (last->next)
	{
		tmp = last;
		last = last->next;

	}
	tmp->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
