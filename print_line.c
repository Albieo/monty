#include "monty.h"

/**
 * pall - prints all nodes in linked list
 * @stack: the head of linked list
 * @line_number: the number contained in list, can be NULL
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
		return;

	while (ptr != NULL)
	{
		printf("%i\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the first node in linked list
 * @stack: the head of linked list
 * @line_number: the number contained in list, can be NULL
*/
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
		return;

	printf("%i\n", ptr->n);
}
