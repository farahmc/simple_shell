#include <stdio.h>
#include "shell.h"

/**
 * _strcmp- compare 2 strings
 * @s1: first string
 * @s2: second string to compare
 *
 * Description: compare each value between 2 strings
 * if the value is the same, return a 0
 * if the value is larger, return a positive number
 * if the value is smaller, return a negative number
 *
 * Return: the difference in value
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	return (s1[i] - s2[i]);
}

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

int builtins (char *string)
{
	if (_strcmp(string, "exit") == 0)
		exit();

	if (_strcmp(string, "env") == 0)
		_env();

	if (_strcmp(string, "cd") == 0)
		_cd();

	error();
	return (0);
}

/**
 * cd - change directory
 * @path: path to change to
 *
 * Return: changed path
 */

int _cd(char *path)
{
	return (chdir(path));
}
