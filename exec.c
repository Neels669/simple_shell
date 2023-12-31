#include "shell.h"

/**
 * Pass_Execve - execve
 *
 * Return: Always 0.
 */
int Pass_Execve(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printString("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printString("After execve\n");
	return (0);
}
