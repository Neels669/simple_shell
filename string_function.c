#include "shell.c"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printString - Function that prints a string
 * @str: Pointer to string
 *
 * Return: Nothing
 */
void printString(const char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}
