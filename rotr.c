#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation (unused)
 *
 * Description: The last element of the stack becomes the top element of the
 * stack.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	int number;
	stack_t *tmp = *stack;

	(void)line_number;

	if (tmp == NULL || tmp->next == NULL)
		return;

	tmp = (*stack)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;

	number = tmp->n;
	while (tmp->prev != NULL)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	tmp->n = number;
}
