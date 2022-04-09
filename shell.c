#include "shell.h"

/**
 * main - the loop for our shell
 *
 * Return: 0 on success, 1 on fail
 */


int main(int argc, char *argv[])
{
	char *buffstring;

	signal(SIGINT, sighandler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (prompt() == -1)
			{
				errormessage(argv[0]);
				return (1);
			}
		}

		buffstring = readaline();

		if (buffstring == NULL)
		{
			errormessage(argv[0]);
			return (1);
		}

		if (processinput(buffstring, argc, argv) == 1)
			return (1);
	}

	return (0);
}
