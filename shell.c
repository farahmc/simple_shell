#include "shell.h"

int main(void)
{
	char *buffstring, *errorstring, *path, *argv[10];

	signal(SIGINT, sighandler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (prompt() == -1)
				return (1);
		}

		buffstring = readaline();
		if (buffstring == NULL)
			return (1);

		if (buffertokens(argv, buffstring) == 1)
			return (1);

		free(buffstring);
		errorstring = _strdup(argv[0]);
		printf("errorstring is %s\n", errorstring);
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
		printf("errorstring is %s & argv[0] is %s\n", errorstring, argv[0]);
		if (*argv[0] != '/' || checkpath(argv[0]) == 1)
			error(errorstring);

		else if (forkwaitexec(argv) == 1)
			error(errorstring);

		free(errorstring);
		freeargv(argv);
	}
	return (0);
}
