#include "shell.h"

char *file_path(char **argv)
{
	int i = 0, j = 0, test;
	char *path = NULL, *token = NULL, *command = NULL; 
	char **pathtoken;

	command = argv[0];
	if (command[0] == '/')
		return (argv[0]);
	else
	{
		path = getenv("PATH");
		token = strtok(path, ":");
		for (i = 0; token != NULL; i++)
		{
			pathtoken[i] = token;
			puts(pathtoken[i]);
			token = strtok(NULL, ":");
		}
		for (j = 0; j < i; j++)
		{
			find the length of pathtoken[j]
			find the length of arvg[0]
			malloc length1 + length2 + 2
			copy in the pathtoken + / + argv[0] + '\0' 
		}
		for (j = 0; j < i; j++)
		{
			test = access(pathtoken[j], F_OK);
			if (test == 0)
				command = pathtoken[j];	
			else
				free(pathtoken[j]
		}
	return (command);
}

int main(void)
{
	char *argv[2];
	
	argv[0] = "ls";
	argv[1] = "-la";
	char *filepath = file_path(argv);
	printf("filepath = %s\n", filepath);
	return (0);
}
