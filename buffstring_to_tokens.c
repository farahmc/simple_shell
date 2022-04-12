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

	token = _strtok(buffer, " \t\n\r");

	if (token == NULL)
		return (1);

	while (token != NULL)
	{
		argv[idx] = token;
		token = _strtok(NULL, " \t\n\r");
		idx++;
	}
	argv[idx] = NULL;

	return (0);
}
