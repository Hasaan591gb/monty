#include "monty.h"

void free_stack(stack_t *head);

inout_t inout = {0};

/**
 * main - entry point for monty interpreter
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char line[1024];
	unsigned int line_number = 0;
	char *int_str;
	int i;
	char *command;
	stack_t *my_stack = NULL;
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
					{"pint", pint}, {"pop", pop},
					{"swap", swap}, {"add", add},
					{"nop", nop}, {"sub", sub},
					{"div", divi}, {"mul", multi},
					{"mod", modu}, {"pchar", pchar},
					{"pstr", pstr}, {"rotl", rotl},
					{"rotr", rotr}, {NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp))
	{
		line_number++;
		command = strtok(line, " \n");
		if (command == NULL || command[0] == '#')
			continue;
		if (strcmp(command, "stack") == 0)
		{
			inout.status = 0;
			continue;
		}
		if (strcmp(command, "queue") == 0)
		{
			inout.status = 1;
			continue;
		}
		if (strcmp(command, "push") == 0)
		{
			int_str = strtok(NULL, " \n");
			if (int_str == NULL || (atoi(int_str) == 0 && int_str[0] != '0'))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			instructions[0].f(&my_stack, atoi(int_str));
			continue;
		}

		for (i = 1; instructions[i].opcode; i++)
		{
			if (strcmp(command, instructions[i].opcode) == 0)
			{
				instructions[i].f(&my_stack, line_number);
				break;
			}
		}

		if (i == 15)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
			exit(EXIT_FAILURE);
		}
	}

	fclose(fp);
	free_stack(my_stack);

	return (0);
}

/**
 * free_stack - frees a stack_t stack
 * @head: pointer to the head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (head != NULL)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
