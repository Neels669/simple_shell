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
 * execute_command - Execve, wait and fork
 * @command_path: path
 *
 * Return: 1 on success
 */
void execute_command(const char *command_path)
{
	pid_t child_pid;
	int status;
	char *argv[2];
	argv[0] = (char *)command_path;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (child_pid == 0)
	{
		printString(command_path);
		printString("\n");
		if (execve(command_path, argv, NULL) == -1)
		{
			perror("Error executing command");
			exit(1);
		}
	}
	else
	{
		wait(&status);
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
	char *ls_dir = "/bin/ls";
	DIR *dir;
	struct dirent *entry;
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
		execute_command(args[0]);
		free(buffer);
	}
	dir = opendir(ls_dir);

	if (dir == NULL)
	{
		perror("Error opening directory");
		return (1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			char command_path[256];
			printString(ls_dir);
			printString("\n");
			my_strcpy(command_path, ls_dir);
			my_strcat(command_path, "/");
			my_strcat(command_path, entry->d_name);
			execute_command(command_path);
		}
	}
	closedir(dir);
	return (0);
}
