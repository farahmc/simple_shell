#include "shell.h"

void sighandler(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

int prompt(void)
{
	return (write(STDOUT_FILENO, "$ ", 2));
}

char *readaline(void)
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
