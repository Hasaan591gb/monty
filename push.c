#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 *
 * Description: This function pushes an element to the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *local_stack;
	stack_t *tmp = *stack;

	local_stack = malloc(sizeof(stack_t));
	if (local_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	local_stack->n = line_number;
	local_stack->next = NULL;
	local_stack->prev = NULL;

	if (*stack == NULL)
		*stack = local_stack;
	else
	{
		if (inout.status == 0)
		{
			(*stack)->prev = local_stack;
			local_stack->next = *stack;
			*stack = local_stack;
		}
		else if (inout.status == 1)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;

			tmp->next = local_stack;
			local_stack->prev = tmp;
		}
	}
}
