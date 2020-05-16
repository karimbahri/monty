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
/**
 *pchar -prints the char at the top of the stack.
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{


		if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		putchar((*stack)->n);
		putchar('\n');
	}
}

/**
 *pstr -prints the string starting at the top of the stack
 *
 *@stack: pointer of struct
 *@line_number: cont the number of ech line
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{

(void)line_number;
stack_t *tmp = *stack;
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
