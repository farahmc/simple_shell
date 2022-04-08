#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 *
 */
int processinput(char *buffer)
{
	char *errorstring = NULL, *path, *argv[20];

	if (buffertokens(argv, buffer) == 1)
		return (1);

	while (1)
	{
		if (builtins(argv) == 0)
			break;

		if (*argv[0] == '/')
		{
			if (checkpath(argv[0]) == -1)
				break;
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

			if (checkpath(argv[0]) == -1)
				break;
		}
		break;
	}

	forkwaitexec(argv);

	if (errorstring != NULL)
		free(errorstring);

	freeargv(argv);

	return (0);
}
