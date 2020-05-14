#ifndef __MONTY__
#define __MONTY__
/*--------------------------------STRUCTS--------------------------------*/
extern int nb_line;

#define EXTERN int nb_line = 0
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*--------------------------------STRUCTS--------------------------------*/



/*-------------------------------PROTOTYPES-------------------------------*/
void execute_instruction(char *command, stack_t **stack);
stack_t *push_stack(stack_t **stack, int n);
void pall(stack_t **stack, unsigned int line_number);
void (*check_instruction(char *command))(stack_t**, unsigned int);
void check_ifInteger(char *number);
/*-------------------------------PROTOTYPES-------------------------------*/
#endif
