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
	if (buff != NULL)
	{
		free(buff);
	}
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printString("\n");
		}
		exit(0);
	}
}

/**
 * my_execute - Execute built-in commands
 * @args: Array of arguments
 *
 * Return: true if a built-in command is executed, false otherwise
 */
bool my_execute(char **args)
{
	int i;
	if (args[0] == NULL)
	{
		return (true);
	}
	else if (my_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			if (chdir(my_getenv("HOME")) != 0)
			{
				perror("cd");
			}
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
		return (true);
	}
	else if (my_strcmp(args[0], "echo") == 0)
	{
		for (i = 1; args[i] != NULL; i++)
		{
			printString(args[i]);
			printString(" ");
		}
		printString("\n");
		return (true);
	}
	return (false);

	if (my_strcmp(args[0], "env") == 0)
	{
		my_env();
		return (true);
	}
	return (false);
}

/**
 * execute_command - Executing commands
 * @args: Pointer to strings
 *
 * Return: 1 on success
 */
void execute_command(char **args)
{
	pid_t child_pid;
	bool is_builtin;
	int status;
	const char *path;
	int pipefd[2];
	bool create_pipe(int pipefd[2]);

	if (args[0] == NULL)
	{
		return;
	}
	is_builtin = my_execute(args);
	if (is_builtin)
	{
		return;
	}
	if (my_strcmp(args[0], "exit") == 0)
	{
		_EOF(-1, NULL);
	}
	if (!create_pipe(pipefd))
	{
		fprintf(stderr, "Error creating pipe.\n");
	}
	if (args[0][0] == '/')
	{
		execv(args[0], args);
		perror("Failed");
		exit(1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("execvp failed");
		exit(1);

		path = my_getenv("PATH");

		if (path != NULL)
		{
			char *path_copy = my_strdup(path);
			char *dir = strtok(path_copy, ":");

			while (dir != NULL)
			{
				char full_path[PATH_MAX];
				my_strcpy(full_path, dir);
				my_strcat(full_path, "/");
				my_strcat(full_path, args[0]);

				if (access(full_path, X_OK) == 0)
				{
					execv(full_path, args);
					perror("failed");
					free(path_copy);
					exit(1);
				}
				dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		printString(args[0]);
		printString("\n");
		exit(1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}

/**
 * main - Shell start
 * @argc: argument count
 * @argv: void
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	char *args[MAX_ARGS];
	size_t buffer_size = 0;
	ssize_t line_len = 0;
	char *token;
	int i, arg_index = 0;
	char *commands[MAX_COMMANDS];
	int cmd_idx, command_count;

	(void)argv;
	(void)argc;
	
	signal(SIGINT, command_sign);
	while (1)
	{
		_isatty();
		line_len = getline(&buffer, &buffer_size, stdin);
		if (line_len == -1)
			_EOF(line_len, buffer);

		replace(buffer, ';');

		command_count = 0;

		token = strtok(buffer, "|");
		while (token != NULL)
		{
			if (my_strlen(token) > 0)
			{
				commands[command_count] = my_strdup(token);
				command_count++;
			}
			token = strtok(NULL, "|");
		}
		for (cmd_idx = 0; cmd_idx < command_count; cmd_idx++)
		{
			token = strtok(commands[cmd_idx], DELIMS);
			while (token != NULL)
			{
				if (my_strlen(token) > 0)
				{
					args[arg_index] = my_strdup(token);
					arg_index++;
				}
				token = strtok(NULL, DELIMS);
			}
			args[arg_index] = NULL;

			execute_command(args);

			for(i = 0; i < arg_index; i++)
			{
				free(args[i]);
			}
			arg_index = 0;
		}
		for (i = 0; i < command_count; i++)
		{
			free(commands[i]);
			commands[i] = NULL;
		}
		free(buffer);
		buffer = NULL;
	}
	return 0;
}
