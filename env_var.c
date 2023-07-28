#include "shell.h"

/**
 * execute_path - Check if the program exists in the provided path
 * @path: Path to check
 * @program: Program name to check for
 * @args: Arguments for the program
 *
 * Return: true if the program is found and executed, false otherwise
 */
bool execute_path(const char *path, const char *program, char **args)
{
	char full_path[PATH_MAX];
	struct stat st;

	my_strcpy(full_path, path);
	my_strcat(full_path, "/");
	my_strcat(full_path, program);

	if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode)
			&& (st.st_mode & S_IXUSR))
	{
		execve(full_path, args, NULL);
	}
	return (false);
}

/**
 * my_env - Print the current environment variables
 *
 * Return: void
 */
void my_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printString(*env);
		printString("\n");
		env++;
	}
}

/**
 * my_path - Replace command with its corresponding path.
 * @args: take argumment.
 *
 * Return: args
 */
char *my_path(char *args)
{

	int count = 0;

	newcommand replace_cmd[] = {
		{"echo", "/bin/echo"},
		{"cat", "/bin/cat"},
		{"chmod", "/bin/chmod"},
		{"mkdir", "/bin/mkdir"},
		{"mv", "/bin/mv"},
		{"pwd", "/bin/pwd"},
		{"rm", "/bin/rm"},
		{"rmdir", "/bin/rmdir"},
		{NULL, NULL}};

	while (replace_cmd[count].type_command)
	{
		if (my_strcmp(args, replace_cmd[count].type_command) == 0)
		{
			args = replace_cmd[count].return_funtion;
			break;
		}
		count++;
	}
	return (args);
}

/**
 * add_array - set the command type user made command_array
 * @token: strtok's string delims.
 * @command_array: the array we are inputting the values into
 * Return: none
 */
void add_array(char *token, char **command_array)
{

	int cont = 0;

	while (token)
	{
		if (cont == 0)
		{
			command_array[cont] = my_path(token);
		}
		else
		{
			command_array[cont] = my_path(token);
		}
		token = strtok(NULL, DELIMS);
		cont++;
	}
	command_array[cont] = NULL;
}

bool create_pipe(int pipefd[2])
{
	char read_end[] = "/tmp/pipe_read_end";
	char write_end[] = "/tmp/pipe_write_end";

	if ((pipefd[0] = open(read_end, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
	{
		perror("open read end");
		return false;
	}
	if ((pipefd[1] = open(write_end, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
	{
		perror("open write end");
		close(pipefd[0]);
		return false;
	}
	return true;
}

