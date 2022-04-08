#include "shell.h"

/**
 * builtins - compare input string to builtins
 * @string: string to compare
 *
 * Description: compare input string to builtins
 * if value is 0, perform builtin function
 * else, print error message
 *
 * Return: 0 is success
 */

int builtins(char *string)
{
	if (_strcmp(string, "exit") == 0)
		exit(1);

	if (_strcmp(string, "env") == 0)
		_env();

	if (_strcmp(string, "cd") == 0)
		_cd(string);

	if (_strcmp(string, "setenv") == 0)
		_setenv(string);

	if (_strcmp(string, "setenv") == 0)
		_unsetenv(string);

	error(string);
	return (0);
}

/**
 * _cd - change directory
 * @path: path to change to
 *
 * Return: changed path
 */

int _cd(char *path)
{
	return (chdir(path));
}
