#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int _strlen(char *s)
{
	int i;

	if (s == NULL || *s == '\0')
		return (0);

	for (i = 0; *s != '\0'; s++)
		i++;

	return (i);
}


int _env(char *env) // is parameter right?
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
