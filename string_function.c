#include "shell.h"

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

/**
 * printUnsigned - Convert string
 * @num: Integer to be converted
 *
 * Return: void
 *
 */
void printUnsigned(unsigned int num)
{
	char num_str[20];
	int i = 0;

	do {
		num_str[i++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (int j = i - 1; j >= 0; j--)
	{
		_putchar(num_str[j]);
	}
}
