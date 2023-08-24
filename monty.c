#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *head = NULL;
    FILE *file;
    char line[50];
    char *function;
    char *arg_str;
    int i, argument = 0;
    struct
    {
        char *name;
        int index;
    }

    functions[] = {
        {"push", 0},
        {"pall", 1},
        {"pint", 2},
        {"pop", 3},
        {"swap", 4},
        {"add", 5},
        {"nop", 6},
        {NULL, -1}
    };
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    if (argc != 2)
    {
        printf("Usage: ./monty filename.m\n");
        return (1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return (1);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        function = strtok(line, " \n");
        arg_str = strtok(NULL, " \n");

        if (strcmp(function, "push") == 0 && arg_str == NULL)
        {
            printf("L<line_number>: usage: push integer\n");
            exit (EXIT_FAILURE);
        }

        if (arg_str != NULL)
            argument = atoi(arg_str);


        if (function != NULL)
        {
            for (i = 0; functions[i].name != NULL; i++)
            {
                if (strcmp(function, functions[i].name) == 0)
                {
                    instructions[functions[i].index].f(&head, argument);
                    break;
                }
            }
        }
    }

    fclose(file);

    return (0);
}
