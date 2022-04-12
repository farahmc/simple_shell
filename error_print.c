#include "shell.h"

/**
 * error_print - prints an error msg
 * @progname: is the argv[0] on call
 * @command: is the inputted shell command
 * @cmdcount: number of commands entered so far
 * Return: is void
 */

void error_print(char *progname, char *command, int cmdcount)
{
	int proglen = 0, commlen = 0;
	char digit[3];

	proglen = _strlen(progname);
	commlen = _strlen(command);
	if (cmdcount < 10)
	{
		digit[0] = '0' + cmdcount;
		digit[1] = '\0';
	}
	else
	{
		digit[0] = (cmdcount % 10) + '0';
		digit[1] = (cmdcount / 10) + '0';
		digit[2] = '\0';
	}
	write(STDOUT_FILENO, progname, proglen);
	write(STDOUT_FILENO, ": ", 2);
	if (cmdcount > 10)
		write(STDOUT_FILENO, digit, 2);
	else
		write(STDOUT_FILENO, digit, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command, commlen);
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * error_cd - prints an error msg
 * @progname: is the argv[0] on call
 * @command: is the inputted shell command
 * @cmdcount: number of commands entered so far
 * Return: is void
 */

void error_cd(char *progname, char *command, int cmdcount)
{
	int proglen = 0, commlen = 0;
	char digit[3];

	proglen = _strlen(progname);
	commlen = _strlen(command);
	if (cmdcount < 10)
	{
		digit[0] = '0' + cmdcount;
		digit[1] = '\0';
	}
	else
	{
		digit[0] = (cmdcount % 10) + '0';
		digit[1] = (cmdcount / 10) + '0';
		digit[2] = '\0';
	}
	write(STDOUT_FILENO, progname, proglen);
	write(STDOUT_FILENO, ": ", 2);
	if (cmdcount > 10)
		write(STDOUT_FILENO, digit, 2);
	else
	write(STDOUT_FILENO, digit, 1);
	write(STDOUT_FILENO, ": cd: can't cd to", 17);
	write(STDOUT_FILENO, command, commlen);
	write(STDIN_FILENO, "\n", 1);
}
