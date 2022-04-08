#include "shell.h"

/**
 * buffertokens - breaks up buffer string into tokens
 * @argv: the array of string to store the tokens
 * @buffer: the string to be broken up
 * Return: 0 for success or 1 for malloc error
 */
int buffertokens(char **argv, char *buffer)
{
	int idx = 0;
	char *token = NULL;

	token = strtok(buffer, " \t");

	while (token != NULL)
	{
		argv[idx] = _strdup(token);

		if (argv[idx] ==  NULL)
		{
			idx--;
			while (idx >= 0)
			{
				free(argv[idx]);
				idx--;
			}
			free(buffer);
			return (1);
		}
		token = strtok(NULL, " \t");
		idx++;
	}
	argv[idx] = NULL;
	free(buffer);
	return (0);
}

/**
 * freeargv - free the memory at each pointer in the array
 * @argv: pointer to the start of the array of strings
 * Return: nothing
 */
void freeargv(char **argv)
{
	int idx = 0;

	while (argv[idx] != NULL)
	{
		free(argv[idx]);
		idx++;
	}
}
