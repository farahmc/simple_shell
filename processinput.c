#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 * @argv: an array of strings with command and arguments
 * @progName: a string containing the program name
 * @cmds: a counter of the commands into our shell in the session
 * Return: always 0
 */
int processinput(char *buffer, char *argv[], char *progName, int cmds)
{
	char *errorstring = NULL, *path = NULL;

	if (builtins(argv, buffer) == 0)
		return (0);
	if (*argv[0] == '/')
	{
		if (checkpath(argv[0]) == 1)
		{
			error_print(progName, argv[0], cmds);
			return (0);
		}
	}
	else
	{
		errorstring = _strdup(argv[0]);
		path = findpath(argv[0], errorstring);
		if (path == NULL)
			return (0);
		else if (path == errorstring)
		{
			free(errorstring);
			if (access(argv[0], F_OK | X_OK) != 0)
			{
				error_print(progName, argv[0], cmds);
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
