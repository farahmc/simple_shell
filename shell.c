#include "shell.h"

/**
 * main - the loop for our shell
 * @argc: the number of arguments passed in
 * @argv: an array of string containing arguments
 * Return: 0 on success, 1 on fail
 */

int main(void)
{
	char *buffstring = NULL;
	char *av[20];

	signal(SIGINT, sighandler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}

		buffstring = readinput();

		if (buffstring == NULL)
			exit(1);

		buffertokens(av, buffstring);

		if (processinput(buffstring, av) == 1)
			exit(1);

		free(buffstring);
	}

	return (0);
}
