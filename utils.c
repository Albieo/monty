#include "monty.h"

void add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;
	int count = 0;
	int sum = 0;

	if (ptr == NULL || ptr->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit (EXIT_FAILURE);
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

void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = *stack;
	stack_t *second = first->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		exit (EXIT_FAILURE);
	}

	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}

void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	return;
}
