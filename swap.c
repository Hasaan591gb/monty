#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: This function swaps the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error
 * message and exits with a status of EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = number;
}
