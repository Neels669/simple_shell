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

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

int _putchar(char c);
void printString(const char *str);
void printUnsigned(unsigned int num);
void printSigned(int num);

int my_strcmp(const char *str1, const char *str2);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

bool execute_path(const char *path, const char *program, char **args);
char *my_getenv(const char *name);

#endif
