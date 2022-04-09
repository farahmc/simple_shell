#include "shell.h"

int rw(int fd)
{
	char *buffer;
	int r, w;

	buffer = malloc(1024);
	r = read(fd, buffer, 1024);
	w = write(STDOUT_FILENO, buffer, r);
	if (w == -1)
	{
		free(buffer);
		return(0);
	}
	free(buffer);
	close(fd);
	return (0);
}

int _help(char *string)
{
	int fd;

	if (_strcmp(string, "env") == 0)
	{
		fd = open("help-env", O_RDONLY);
		rw(fd);
	}

	if (_strcmp(string, "exit") == 0)
	{
		fd = open("help-exit", O_RDONLY);
		rw(fd);
	}

	if (_strcmp(string, "cd") == 0)
	{
		fd = open("help-cd", O_RDONLY);
		rw(fd);
	}

	if (_strcmp(string, "help") == 0)
	{
		fd = open("help-help", O_RDONLY);
		rw(fd);
	}
	return (0);
}
