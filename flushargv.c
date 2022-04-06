#include <stdlib.h>

/**
 * flushargv - initialises pointers in an array of strings to NULL
 * @argv: the array of strings to be traversed
 * @size: the size of the array
 * Return: nothing
 */
void flushargv(char **argv, int size)
{
	int i = 0;

	while (i < size)
	{
		argv[i] = NULL;
		i++;
	}
}
