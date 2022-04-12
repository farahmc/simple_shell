#include "shell.h"

/**
 * main - the loop for our shell
 * @argc: the number of arguments passed in
 * @argv: an array of string containing arguments
 * Return: 0 on success, 1 on fail
 */

int main(int argc, char **argv)
{
	char *buffstring = NULL, *progName;
	char *av[20];

	signal(SIGINT, sighandler);
	progName = argv[0];

	while (argc)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}

		buffstring = readinput();

		if (buffstring == NULL)
			return (0);

		buffertokens(av, buffstring);

		if (processinput(buffstring, av, progName) == 1)
			exit(1);

		free(buffstring);
	}

	return (0);
}
