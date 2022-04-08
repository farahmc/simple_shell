#include "shell.h"

/**
 * main - the loop for our shell
 *
 * Return: 0 on success, 1 on fail
 */


int main(void)
{
	char *buffstring;

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

		processinput(buffstring);
	}

	return (0);
}
