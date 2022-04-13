#include "shell.h"

/**
 * rw - read and write file in stdout
 * @fd: file descriptor
 * Description: read, allocate space and and write file in stdout
 * Return: 0 is success
 */

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
		return (0);
	}
	free(buffer);
	close(fd);
	return (0);
}

/**
* _help - chooses correct help file to display in stdout
* @string: matching argument to help command
* Description: match argument with string to display correct help file
* Return: 0 is success
*/

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

	if (_strcmp(string, "setenv") == 0)
	{
		fd = open("help-setenv", O_RDONLY);
		rw(fd);
	}
	return (0);
}
