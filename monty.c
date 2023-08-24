#include "monty.h"

void processLine(char *line, stack_t **head)
{
	char *token;
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

	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			arg_str = strtok(NULL, " \n\t");
			if (arg_str == NULL)
			{
				printf("L<line_number>: usage: push integer\n");
				exit(EXIT_FAILURE);
			}
			argument = atoi(arg_str);
		}
		else
			argument = 0;

		for (i = 0; functions[i].name != NULL; i++)
		{
			if (strcmp(token, functions[i].name) == 0)
			{
				instructions[functions[i].index].f(head, argument);
				break;
			}
		}
		token = strtok(NULL, " \n\t");
	}
}

void processFile(const char *filename)
{
	stack_t *head = NULL;
	FILE *file;
	char line[50];

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Failed to open the file.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
		processLine(line, &head);

	fclose(file);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./monty filename.m\n");
		return (1);
	}

	processFile(argv[1]);

	return (0);
}
