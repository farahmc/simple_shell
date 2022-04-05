#include "shell.h"

/**
*_getenv - get the PATH
*@member: PATH string
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

void print_env(char *name)
{
	int i = 0;
	char *token;

	token = strtok(name, "=");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		printf("token[%d] => %s\n", i, token);
		i++;
		token = strtok(NULL, ":");
	}
}

int main()
{
	char *path, *pwd, *oldpwd;
	unsigned int i = 0;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}	
	path = _getenv("PATH");
	if (path != NULL)
	{
		printf("%s\n", path);
		print_env(path);
	}
	else
		perror("PATH not found");
	pwd = _getenv("PWD");
	printf("%s\n", pwd);
	oldpwd = _getenv("OLDPWD");
	printf("%s\n", oldpwd);
	return (0);
}
