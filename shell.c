#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void sighandler(int sig_num)
{
	signal(SIGINT, sighandler);
	if (sig_num == SIGINT)
		write(1, "\n->$", 4);
/*	fflush(stdout);*/
}

char *readaline(void)
{
	ssize_t read = 0;
	unsigned long int slen = 0;
	char *buff = NULL;

	read = getline(&buff, &slen, stdin);
	if (read == -1)
	{
		free(buff);
		exit(0);
	}
	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';
	return (buff);
}

int main(void)
{
	int i = 0, j = 0, k = 0, status = 1, writeflag = 0;
	char *buffstring, *token = NULL, *argv[10], *path;
	pid_t pid;

	signal(SIGINT, sighandler);
	path = _getenv("PATH");
	if (path == NULL)
		return (1);
	while (i < 20)
	{
		if (isatty(STDIN_FILENO))
		{
			writeflag = write(1, "->$", 3);
			if (writeflag == -1)
				return (1);
		}
		buffstring = readaline();
		token = strtok(buffstring, " ");
		for (j = 0; token != NULL; j++)
		{
			argv[j] = token;
			token = strtok(NULL, " ");
		}
		argv[j] = token;
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (pid == 0)
			execve(argv[0], argv, NULL);
		wait(&status);
		if (pid != 0)
			i++;
		for (k = 0; k <= j; k++)
			argv[k] = NULL;
	}
	return (0);
}
