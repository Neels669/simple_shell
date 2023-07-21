#include "shell.h"

/**
 * my_strcmp - Function for string comparison
 * @str1: First string pointer
 * @str2: Second string pointer
 *
 * Return: strcmp
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * my_strlen - Function for length of string
 * @str: pointer to string
 *
 * Return: length
 */
size_t my_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
