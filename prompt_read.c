#include "shell.h"

/**
 * sighandler - manages signal received by ctrl c
 * @sig_num: the int representation of ctrl c
 * Return: nothing
 */
void sighandler(int sig_num)
{
	if (sig_num == SIGINT)
		if (write(STDOUT_FILENO, "\n$ ", 3) == -1)
			exit(1);
}

/**
 * prompt - writes a prompt to stdout
 *
 * Return: number of chars written or -1 for failure
 */
void prompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 2) == -1)
		exit(1);
}

/**
 * readinput - reads a line from stdin to a buffer
 *
 * Return: pointer to the buffer containing input
 */
char *readinput(void)
{
	int read;
	size_t bufflength = 0;
	char *buffer = NULL;

	read = getline(&buffer, &bufflength, stdin);

	if (read == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}

	if (buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';

	return (buffer);
}
