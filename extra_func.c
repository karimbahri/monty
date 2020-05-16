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
 *rotl -prints the string starting at the top of the stack
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

		while (tmp->next)
		{
			swap(&tmp, line_number);
			tmp = tmp->next;
		}

}
