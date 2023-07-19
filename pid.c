#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * show_pid - PID
 *
 * Return: Always 0.
 */
int show_pid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printSigned(my_pid);
	printString("\n");

	return (0);
}
