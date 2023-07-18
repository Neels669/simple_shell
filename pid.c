#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printUnsigned(my_pid);
	printString("\n");

	return (0);
}
