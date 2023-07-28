#ifndef SHELL_HDR
#define SHELL_HDR

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdbool.h>
#include <limits.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define MAX_COMMANDS 100
#define DELIMS " \t\n"

int _putchar(char c);
void printString(const char *str);
void printUnsigned(unsigned int num);
void printSigned(int num);
void _isatty(void);

int my_strcmp(const char *str1, const char *str2);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);

extern char **environ;

bool execute_path(const char *path, const char *program, char **args);
char *my_getenv(const char *name);
void my_env(void);

char *my_path(char *args);
void add_array(char *token, char **command_array);

/**
 * struct shellcmd - structure for commands
 * @type_command: command in user
 * @return_funtion: return function.
 */
typedef struct shellcmd
{
	char *type_command;
	char *return_funtion;

} newcommand;

#endif
