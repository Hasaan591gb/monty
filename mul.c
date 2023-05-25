#include "monty.h"

/**
 * multi - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void multi(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack;

	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	local_stack = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(local_stack);
}
