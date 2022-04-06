#include "shell.h"

/**
 * _env - print environment variables
 *
 * Return: 0 is success
 */

int _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
