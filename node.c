#include "monty.h"

stack_t *createNode(int n)
{
    stack_t *temp = malloc(sizeof(stack_t));
    if (temp == NULL)
        return (NULL);

    temp->n = n;
    temp->prev = NULL;
    temp->next = NULL;

    return (temp);
}

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new = createNode(line_number);
    if (new == NULL)
        return;

    new->next = *stack;
    new->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new;

    *stack = new;
}

void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *temp = *stack;
    if (*stack == NULL)
    {
        printf("L<line_number>: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }

    *stack = temp->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}
