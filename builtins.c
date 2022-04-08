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

int builtins(char *string, char *argv[20])
{
	int errflag = 0;

	if (_strcmp(string, "exit") == 0)
		exit(1);

	if (_strcmp(string, "env") == 0)
		_env();

	if (_strcmp(string, "cd") == 0)
		_cd(string);

	if (_strcmp(string, "setenv") == 0)
		errflag = _setenv(argv);

	if (_strcmp(string, "setenv") == 0)
		errflag = _unsetenv(argv);

	if (errflag == -1)
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

/**
 * _setenv - performs the builtin setenv
 * @agrv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */

int _setenv(char *argv[20])
{
	count = 0, overwrite = 0, argvlen, returnflag = 0;

	while (argv[count] != NULL)
		count++;

	if (count < 2)
		return (-1);
	if (count > 3)
		return (-1); /*must have argv[0] and argv[1] and maybe have argv[2] */
	if (count == 2)
	{
		argvlen = _strlen[argv2];
		if (argvlen != 1)
			return (-1);
		if (argv[2] == '1')
			overwrite = 1;
		else if (argv[2] == '0')
			overwrite = 0;
		else
			return (-1);		/* overwrite can only be a 0 or 1 */
	}
	returnflag = setenv(argv[0], argv[1], overwrite);
	
	return (returnflag);
}

/**
 * _unsetenv - performs the builtin unsetenv
 * @agrv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */
int _unsetenv(char *argv[20])
{
	count = 0, returnflag = 0;

	while (argv[count] != NULL)
		count++;

	if (count != 1)
		return (-1); /*must have argv[0] only */

	returnflag = unsetenv(argv[0]);

	return (returnflag);
}
