#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: This function removes the top element of the stack.
 * If the stack is empty, it prints an error message and exits with
 * a status of EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	local_stack = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(local_stack);
}
