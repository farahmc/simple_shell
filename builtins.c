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
int builtins(char *argv[])
{
	int errflag = 0;

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(1);
	}

	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}

	if (_strcmp(argv[0], "cd") == 0)
	{
		_cd(argv);
		return (0);
	}

	if (_strcmp(argv[0], "setenv") == 0)
	{
		errflag = _setenv(argv);
		if (errflag == -1)
			errormessage(argv[0]);
		return (0);
	}

	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		errflag = _unsetenv(argv);
		if (errflag == -1)
			errormessage(argv[0]);
		return (0);
	}

	return (1);
}

/**
 * _cd - change directory
 * @path: path to change to
 *
 * Return: changed path
 */

int _cd(char *argv[])
{
	int returnflag;
	char *homepath = NULL, *pwd = NULL, *oldpwd = NULL;
	char path[200];
	
	pwd = getcwd(path, 200);
	oldpwd = _strdup(_getenv("OLDPWD"));
	oldpwd = strtok(oldpwd, "=");
	oldpwd = strtok(NULL, "=");
	if (argv[1] == NULL)
	{
		homepath = _strdup(_getenv("HOME"));
		homepath = strtok(homepath, "=");
		homepath = strtok(NULL, "=");
		argv[1] = homepath;
	}
	else 
	{
		if (*argv[1] == '-')
			argv[1] = oldpwd;
	}

	printf("before chdir, argv[1] = %s\n", argv[1]);
	returnflag = chdir(argv[1]);

	if (returnflag == 0)
	{
		setenv("OLDPWD", pwd, 1);
		pwd = getcwd(path, 200);
		setenv("PWD", pwd, 1);
	}
	printf("pwd => %s\n", _getenv("PWD"));
	printf("oldpwd => %s\n", _getenv("OLDPWD"));

	return (returnflag);
}

/**
 * _setenv - performs the builtin setenv
 * @agrv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */

int _setenv(char *argv[])
{
	int count = 0, overwrite = 1, returnflag = 0, argvlen = 0;

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
	returnflag = setenv(argv[1], argv[2], overwrite);

	return (returnflag);
}

/**
 * _unsetenv - performs the builtin unsetenv
 * @agrv: a ptr to a command broken into an array of strings
 * Return: 0 on success, -1 on error
 */
int _unsetenv(char *argv[20])
{
	int count = 0, returnflag = 0;

	while (argv[count] != NULL)
		count++;

	if (count != 1)
		return (-1); /*must have argv[0] only */

	returnflag = unsetenv(argv[1]);

	return (returnflag);
}
