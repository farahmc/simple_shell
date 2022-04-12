#include "shell.h"

/**
 * find_builtin - compares argv[0] to each builtin name
 * @command: our argv[0]
 * Return: 0 if builtin not found, otherwise an int for which builtin
 */

int find_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0)
		return (1);
	if (_strcmp(command, "env") == 0)
		return (2);
	if (_strcmp(command, "help") == 0)
		return (3);
	if (_strcmp(command, "cd") == 0)
		return (4);
	if (_strcmp(command, "setenv") == 0)
		return (5);
	if (_strcmp(command, "unsetenv") == 0)
		return (6);
	return (0);
}

/**
 * builtins - compare input string to builtins
 * @argv: an array of strings containing command and arguments
 * @buffer: string to compare
 *
 * Description: compare input string to builtins
 * if value is 0, perform builtin function
 * else, print error message
 *
 * Return: 0 is success
 */
int builtins(char *argv[], char *buffer)
{
	int errflag = 0, caseno = find_builtin(argv[0]);

	switch (caseno)
	{
		case 1:
			free(buffer);
			exit(0);
		case 2:
			_env();
			return (0);
		case 3:
			_help(argv[1]);
			return (0);
		case 4:
			_cd(argv);
			return (0);
		case 5:
			errflag = _setenv(argv);
			if (errflag == -1)
				perror(argv[0]);
			return (0);
		case 6:
			errflag = _unsetenv(argv);
			if (errflag == -1)
				perror(argv[0]);
			return (0);
		default:
			return (1);
	}
}
/**
 * _cd - change directory
 * @argv: any array of strings containing command and arguments
 *
 * Return: changed path
 */
void _cd(char *argv[])
{
	int flag;
	char *path, *pwd, *oldpwd, *holdold, *home, *holdhome;
	char buff[200];

	pwd = getcwd(buff, 200);
	holdold = _strdup(_getenv("OLDPWD"));
	oldpwd = _strtok(holdold, "=");
	oldpwd = _strtok(NULL, "=");
	holdhome = _strdup(_getenv("HOME"));
	home = _strtok(holdhome, "=");
	home = _strtok(NULL, "=");

	if (argv[1] == NULL)
		path = home;
	else
	{
		if (*argv[1] == '-')
			path = oldpwd;
		else
			path = argv[1];
	}

	flag = chdir(path);

	if (flag == 0)
	{
		setenv("OLDPWD", pwd, 1);
		pwd = getcwd(buff, 200);
		setenv("PWD", pwd, 1);
	}
	else
		perror(argv[0]);
	free(holdold);
	free(holdhome);
}

/**
 * _setenv - performs the builtin setenv
 * @argv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */

int _setenv(char *argv[])
{
	int count = 0, overwrite = 1, flag = 0, argvlen = 0;

	while (argv[count] != NULL)
		count++;

	if (count < 3)
		return (-1);
	if (count > 4)
		return (-1); /*must have argv[0] and argv[1] and maybe have argv[2] */
	if (count == 4)
	{
		argvlen = _strlen(argv[3]);
		if (argvlen != 1)
			return (-1);
		if (*argv[2] == '1')
			overwrite = 1;
		else if (*argv[2] == '0')
			overwrite = 0;
		else
			return (-1);		/* overwrite can only be a 0 or 1 */
	}
	flag = setenv(argv[1], argv[2], overwrite);

	return (flag);
}

/**
 * _unsetenv - performs the builtin unsetenv
 * @argv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */
int _unsetenv(char *argv[20])
{
	int count = 0, flag = 0;

	while (argv[count] != NULL)
		count++;

	if (count != 2)
		return (-1); /*must have argv[0] and arg[1] only */

	flag = unsetenv(argv[1]);

	return (flag);
}
