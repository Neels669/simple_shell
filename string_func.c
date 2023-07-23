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

/**
 * my_strdup - Allocate memory and copy string
 * @str: String
 *
 * Return: strdup
 */
char *my_strdup(const char *str)
{
	size_t len = my_strlen(str);
	char *new_str = (char *)malloc(len + 1);
	size_t i;

	if (new_str == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}

/**
 * my_strcpy - copy one string to another
 * @dest: Destination
 * @src: source
 *
 * Return: Dest
 */
char *my_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * my_strcat - Concatenate one string to another
 * @dest: Destination string
 * @src: Source
 *
 * Return: Dest
 */
char *my_strcat(char *dest, const char *src)
{
	size_t dest_len = my_strlen(dest);
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
