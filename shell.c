#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void sighandler(int sig_num)
{
	signal(SIGINT, sighandler);
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

int prompt()
{
	return (write(STDOUT_FILENO, "$ ", 2));
}

char * readaline()
{
	int  read;
	size_t bufflength = 0;
	char *buffer = NULL;

	read = getline(&buffer, &bufflength, stdin);

	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}

	if (buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';

	return (buffer);
}

int error(char *firstarg)
{
	if (write(STDOUT_FILENO, firstarg, _strlen(firstarg)) == -1)
		return (1);

	perror(" ");

	return (0);
}

int main(void)
{
	int idx;
	char *buffstring, *token, *path, *argv[10];

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

		token = strtok(buffstring, " ");

		for (idx = 0; token != NULL; idx++)
		{
			argv[idx] = token;
			token = strtok(NULL, " ");
		}
		argv[idx] = token;

		path = file_path(*argv);

		if (path == NULL)
			error(argv[0]);

		argv[0] = path;

		if (forkwaitexec(argv) == 1)
			error(argv[0]);

		flushargv(argv);
		free(buffstring);
	}
	return (0);
}
