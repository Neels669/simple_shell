#include "shell.h"

/**
 * main - fork,wait & execve
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
			char *envp[] = {NULL};
			execve("/bin/ls", argv, envp);
		}
		else
		{
			wait(NULL);
			printString("Child process exited.\n");
		}
		return (0);
	}
}

