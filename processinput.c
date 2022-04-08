#include "shell.h"

/**
 * processinput - takes a string of instructions from stdin and
 * emmulates a shell
 * @buffer: the string with input instructions
 *
 */
int processinput(char *buffer)
{
	char *errorstring, *path, *argv[20];

	if (buffertokens(argv, buffer) == 1)
		return (1);

	errorstring = _strdup(argv[0]);

	if (path_given(argv[0]) == 0)
	{
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
	}

	if (*argv[0] != '/' || checkpath(argv[0]) == 1)
	{
		errormessage(errorstring);
	}
	else
	{
		forkwaitexec(argv);
		free(errorstring);
	}

	freeargv(argv);
	return (0);
}
