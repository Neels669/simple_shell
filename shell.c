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
 * execute_command - Execute external commands
 * @args: Array of arguments
 * @envp: Environment variables
 *
 * Return: 1 on success
 */
int execute_command(char **args, char **envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (1);
}

/**
 * main - Shell start
 * @ac: Count in av
 * @av: Array of strings
 * @envp: NULL terminated array of strings
 *
 * Return: prompt
 */
int main(int ac, char **av, char **envp)
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
			args[arg_index] = token;
			arg_index++;

			token = strtok(NULL, delimiters);
		}
		args[arg_index] = NULL;

		if (strcmp(args[0], "exit") == 0)
		{
			_EOF(-1, buffer);
		}
		execute_command(args, envp);
	}
	free(buffer);
	return (0);
}
