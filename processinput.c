#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 * @argv: an array of strings with command and arguments
 * Return: always 0
 */
int processinput(char *buffer, char *argv[])
{
	char *errorstring = NULL, *path = NULL;

	if (builtins(argv, buffer) == 0)
		return (0);
	if (*argv[0] == '/')
	{
		if (checkpath(argv[0]) == 1)
			return (0);
	}
	else
	{
		errorstring = _strdup(argv[0]);
		if (errorstring == NULL)
		{
			perror(argv[0]);
			if (buffer != NULL)
				free(buffer);
			exit(1);
		}

		path = findpath(argv[0], errorstring);

		if (path == NULL || path == errorstring)
		{
			perror(argv[0]);
			free(errorstring);
			return (0);
		}
		else
		{
			free(errorstring);
			argv[0] = path;
		}
	}
	forkwaitexec(argv);
	if (argv[0] == path)
		free(argv[0]);
	return (0);
}
