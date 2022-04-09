#include "shell.h"

/**
 * forkwaitexec - forks a child process to execute a command while parent
 * process waits
 * @argv: an array of arguments containing the pathname for the command and
 * any command arguments
 *
 * Return: 0 on success or 1 on fork failure
 */
void forkwaitexec(char **argv)
{
	pid_t childpid;

	childpid = fork();

	if (childpid == -1)
	{
		perror(argv[0]);
		return;
	}

	if (childpid == 0)
		execve(argv[0], argv, NULL);

	wait(&childpid);
}
