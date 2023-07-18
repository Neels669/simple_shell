#include "shell.h"

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printUnsigned(my_pid);
	printString("\n");

	return (0);
}
