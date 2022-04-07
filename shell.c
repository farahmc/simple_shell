#include "shell.h"

void sighandler(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

int prompt()
{
	return (write(STDOUT_FILENO, "$ ", 2));
}

char *readaline()
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
	perror("something has gone awry");
	return (0);
}

int main(void)
{
	char *buffstring, *path, *argv[10];

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

		path = file_path(argv[0]);
		if (path == NULL)
		{
			freeargv(argv);
			return (1);
		}

		if (*argv[0] != '/')
		{
			free(argv[0]);
			argv[0] = path;
		}

		if (forkwaitexec(argv) == 1)
			error(argv[0]);

		freeargv(argv);
	}

	return (0);
}
