#include <stdlib.h>
#include <stdio.h>

/**
 * flushargv - initialises pointers in an array of strings to NULL
 * @argv: the array of strings to be traversed
 *
 * Return: nothing
 */
void flushargv(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		argv[i] = NULL;
		i++;
	}
}
