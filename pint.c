#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: This function prints the value at the top of the stack,
 * followed by a new line. If the stack is empty, it prints an error
 * message and exits with a status of EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
