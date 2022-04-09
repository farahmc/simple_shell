#include "shell.h"

/**
 * sighandler - manages signal received by ctrl c
 * @sig_num: the int representation of ctrl c
 * Return: nothing
 */
void sighandler(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * prompt - writes a prompt to stdout
 *
 * Return: number of chars written or -1 for failure
 */
int prompt(void)
{
	return (write(STDOUT_FILENO, "$ ", 2));
}

/**
 * readaline - reads a line from stdin to a buffer
 *
 * Return: pointer to the buffer containing input
 */
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

/**
 * error - prints error messages to the screen
 * @firstarg: a string containing first argument passed in to
 * the program
 * Return: 0 for success or 1 for failure to write
 */
void errormessage(char *firstarg)
{
	perror(firstarg);
}
