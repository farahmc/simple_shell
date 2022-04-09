#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 *
 */
int processinput(char *buffer, int argc, char *argv[])
{
	char *errorstring = NULL, *path;

	if (argc != 1)
	{
		if (buffertokens(argv, buffer) == 1)
		return (1);
	}
	else
		argv[1] = NULL;

	while (1)
	{
		if (builtins(argv) == 0)
			return (0);

		if (*argv[0] == '/')
		{
			if (checkpath(argv[0]) == 1)
				return (0);
		}
		else
		{
			errorstring = _strdup(argv[0]);
			path = findpath(argv[0], errorstring);
			if (path == NULL)
			{
				free(errorstring);
				freeargv(argv);
				return (1);
			}
			else
			{
				free(argv[0]);
				argv[0] = path;
			}

			if (checkpath(argv[0]) == 1)
				return (0);
		}
		break;
	}

	forkwaitexec(argv);

	if (errorstring != NULL)
		free(errorstring);

	freeargv(argv);

	return (0);
}
