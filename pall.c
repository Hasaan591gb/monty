#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 *
 * Description: This function prints all the values on the stack,
 * starting from the top of the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack = *stack;

	(void)line_number;

	while (local_stack != NULL)
	{
		fprintf(stdout, "%d\n", local_stack->n);
		local_stack = local_stack->next;
	}
}
