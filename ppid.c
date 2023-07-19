#include "shell.h"

/**
 * show_ppid - PPID
 *
 * Return: Always 0.
 */
int show_ppid(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printSigned(my_pid);
	printString("\n");

	return (0);
}
