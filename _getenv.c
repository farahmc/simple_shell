#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
*_getenv - get the env members
*@name: the member name
*Return: pointer to member if found
*/
char *_getenv(const char *name)
{
	int i, j, flag;
	char *current_env = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		flag = 0;
		current_env = environ[i];
		for (j = 0; current_env[j] != '='; j++)
		{
			if (name[j] != current_env[j])
				flag = 1;
		}
		if (flag == 0)
			return (environ[i]);
	}
	return (NULL);
}
