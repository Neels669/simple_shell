#include "shell.h"

int builtin_echo(char **args, char **envp)
{
	for (int i = 1; args[i] != NULL; i++)
	{
		printString(args[i]);
		if (args[i + 1] != NULL)
			printString(" ");
	}
	printString("\n");
	return (0);
}

typedef int (*builtin_handler)(char **args, char **envp);
{
	builtin_command builtin_commands[] = {
		{"echo", builtin_echo},
		{NULL, NULL},
	};
}
