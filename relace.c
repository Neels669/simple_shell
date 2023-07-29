#include "shell.h"

/**
 * replace - character in a string with whitespace
 * @str: string
 * @ch: replace
 *
 * Return: void
 */
void replace(char *str, char ch)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ch)
		{
			str[i] = ' ';
		}
	}
}
