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

//String Functions
int _putchar(char c); //Prints char
void printString(const char *str); //prints string

#endif
