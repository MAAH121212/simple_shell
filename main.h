#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char *findInPATH(char *path, char *file);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name);
char **strtow(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int (*get_op_func(char *s))();
void free_args(char **s);
char *_strdup(char *str);
int _putchar(char c);
int print_string(char *s);

/**
 * struct op - represent an operation
 * @op: operation name
 * @f: a function pointer that represents a function that takes no arguments
 * and return an integer
 */

typedef struct op
{
	char *op;
	int (*f)(void);
} op_t;

#endif
