#include "monty.h"

/**
 * nop - does nothing
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation
 *
 * Description: This function does nothing. It is used as a placeholder
 * for operations that have no effect.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
