#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: This function adds the top two elements of the stack.
 * The result is stored in the second element from the top and the top
 * element is removed. If the stack contains less than two elements,
 * it prints an error message and exits with a status of EXIT_FAILURE.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack;

	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	local_stack = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(local_stack);
}
