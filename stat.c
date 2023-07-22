#include "shell.h"

/**
 * main - stat example
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printString(av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printString(av[i]);
		if (stat(av[i], &st) == 0)
		{
			printString(" FOUND\n");
		}
		else
		{
			printString(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
