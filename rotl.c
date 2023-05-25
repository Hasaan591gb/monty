#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation (unused)
 *
 * Description: The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int number;
	stack_t *tmp = *stack;

	(void)line_number;

	if (tmp == NULL || tmp->next == NULL)
		return;

	number = tmp->n;
	while (tmp->next != NULL)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = number;
}
