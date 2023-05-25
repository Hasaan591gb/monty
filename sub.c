#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack;

	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	local_stack = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(local_stack);
}
