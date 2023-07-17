#include "shell.h"

/**
 * command_sign - Sign to print on output
 * @sign: symbol
 *
 * Return: Void
 */
void command_sign(int sign)
{
	if (sign == SIGINT)
	{
		printString("\n($) ");
	}
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: character buffer
*
* Return: void
*/
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printString("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - Function to dispaly the prompt
 *
 * Return: void
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		printString("($) ");
}

/**
 * main - Command to pass the function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Status
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line_len = 0;

	(void)ac;
	(void)av;

	signal(SIGINT, command_sign);

	_isatty();

	while (1)
	{
		line_len = getline(&buffer, &buffer_size, stdin);
		if (line_len == -1)
			_EOF(line_len, buffer);
		_isatty();
	}

	free(buffer);
	return (0);
}
