#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current operation (unused)
 *
 * Description: The integer stored in each element of the stack is treated as
 * an ASCII value and the corresponding character is printed. The string stops
 * when either the stack is over, the value of the element is 0, or the value
 * of the element is not in the ASCII table.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int number;
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp != NULL)
	{
		number = tmp->n;
		if (number <= 0 || number > 127)
			break;
		printf("%c", number);
		tmp = tmp->next;
	}
	printf("\n");
}
