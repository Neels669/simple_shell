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
		fflush(stdout);
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
 * execute_command - Execve, wait and fork
 * @command_path: path
 *
 * Return: 1 on success
 */
void execute_command(char **args)
{
	pid_t child_pid;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Shell start
 * @ac: Count in av
 * @av: Array of strings
 * @envp: NULL terminated array of strings
 *
 * Return: prompt
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line_len = 0;
	char *token;
	const char *delimiters = " \t\n";
	char *args[64];
	int arg_index = 0;

	(void)ac;
	(void)av;

	signal(SIGINT, command_sign);

	while (1)
	{
		printString("($) ");

		line_len = getline(&buffer, &buffer_size, stdin);
		if (line_len == -1)
			_EOF(line_len, buffer);

		token = strtok(buffer, delimiters);
		while (token != NULL)
		{
			if (my_strlen(token) > 0)
			{
				args[arg_index] = token;
				arg_index++;
			}
			token = strtok(NULL, delimiters);
		}
		args[arg_index] = NULL;
		if (my_strcmp(args[0], "exit") == 0)
		{
			_EOF(-1, buffer);
		}
		execute_command(args);
		free(buffer);
	}
	return (0);
}
