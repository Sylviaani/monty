#include "monty.h"

var_t var = {NULL, NULL, NULL};

/**
 * main - this is the entry point function
 * @argc: this is the number of command line argument(s) passed
 * @argv: this is a string that contains all the argument(s)
 * Return: always 0
 */

int main(int argc, char **argv)
{
	FILE *file;
	size_t size = 0;
	int readline = 0;
	char *line_content;
	size_t line_num = 0;
	stack_t *stack;

	if (argc != )
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;

	if (!file)
	{
		fprint(stedder, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line_content = NULL;
		readline = getline(&line_content, &size, file);
		var.content = line_content;
		line_num++;
		if (readline == -1)
		{
			free(line_content);
			break;
		}
		execute(line_content, &stack, line_num, file);
		free(line_content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
