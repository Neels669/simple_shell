#ifndef SHELL_HDR
#define SHELL_HDR

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
void printString(const char *str);
void printUnsigned(unsigned int num);
void printSigned(int num);

int my_strcmp(const char *str1, const char *str2);
size_t my_strlen(const char *str);

int execute_command(char **args, char **envp);

#endif
