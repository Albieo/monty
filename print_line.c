#include "monty.h"

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

void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr = *stack;
    if (ptr == NULL)
        return;

    printf("%i\n", ptr->n);
}
