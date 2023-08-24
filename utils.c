#include "monty.h"

/**
 * add - adds the first two nodes then delete the added nodes
 * @stack: the head of linked list
 * @line_number: the number contained in list, can be NULL
*/
void add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;
	int count = 0;
	int sum = 0;

	if (ptr == NULL || ptr->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	while (count < 2 && ptr != NULL)
	{
		sum += ptr->n;
		count++;
		ptr = ptr->next;
	}

	if (*stack != NULL)
	{
		*stack = ptr;
		if (ptr != NULL)
			ptr->prev = NULL;
	}

	printf("%i\n", sum);
}

/**
 * swap - swaps the first two nodes
 * @stack: the head of linked list
 * @line_number: the number contained in list, can be NULL
*/
void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = *stack;
	stack_t *second = first->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}

/**
 * nop - doesn't do anything
 * @stack: the head of linked list
 * @line_number: the number contained in list, can be NULL
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
