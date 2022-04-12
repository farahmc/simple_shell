#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 * @argv: an array of strings with command and arguments
 * @progName: a string containing the program name
 * Return: always 0
 */
int processinput(char *buffer, char *argv[], char *progName)
{
	char *errorstring = NULL, *path = NULL;

	if (builtins(argv, buffer) == 0)
		return (0);
	if (*argv[0] == '/')
	{
		if (checkpath(argv[0]) == 1)
		{
			perror(progName);
			return (0);
	}
	else
	{
		errorstring = _strdup(argv[0]);
		if (errorstring == NULL)
		{
			perror(argv[0]);
			free(buffer);
			exit(1);
		}

		path = findpath(argv[0], errorstring);

		if (path == NULL)
			return (0);
		else if (path == errorstring)
		{
			free(errorstring);
			if (access(argv[0], F_OK | X_OK) != 0)
			{
				perror(progName);
				return (0);
			}
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
