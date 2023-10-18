#include "main.h"

/**
 * exit_shell - Entry point
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

int exit_shell(void)
{
	return (2);
}

/**
 * print_env - Entry point
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
	print_string(environ[i]);
	_putchar('\n');
	}
	return (1);
}

/**
 * get_op_func - Entry point
 * @s: char
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

int (*get_op_func(char *s))()
{
	op_t ops[] = {
		{"env", print_env},
		{"exit", exit_shell},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (i < 2)
	{
		if (_strcmp(s, ops[i].op) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}

