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
