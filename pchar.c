#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: The integer stored at the top of the stack is treated as an
 * ASCII value and the corresponding character is printed.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;
	if (number < 0 || number > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", number);
}
