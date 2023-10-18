#include "main.h"

/**
 * pathcat - Entry point
 * @s1: list
 * @s2: list
 * Description: hi
 * Return: void
 */

char *pathcat(char *s1, char *s2)
{
	char *fullPath;
	int i, j;

	fullPath = malloc(sizeof(s1) + sizeof(s2) + 2);
	if (fullPath == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		fullPath[i] = s1[i];
	fullPath[i] = '/';
	i++;
	for (j = 0; s2[j] != '\0'; i++, j++)
		fullPath[i] = s2[j];
	fullPath[i] = '\0';

	return (fullPath);

}

/**
 * findInPATH - Entry point
 * @path: string dest
 * @file: string
 * Description: 'Check if a character is uppercase'
 * Return: Always 0 (Success)
 */

char *findInPATH(char *path, char *file)
{
	char *token, *cwd;
	int found;

	found = access(file, F_OK);
	if (found == 0)
	{
		return (_strdup(file));
	}

	cwd = malloc(1024);

	getcwd(cwd, 1024);
	token = strtok(path + 5, ":");
	while (token != NULL)
	{
		chdir(token);
		found = access(file, F_OK);
		if (found == 0)
		{
			chdir(cwd);
			free(cwd);
			return (pathcat(token, file));
		}
		token = strtok(NULL, ":");
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * free_args - Entry point
 * @s: list
 * Description: hi
 * Return: void
 */

void free_args(char **s)
{
	int i;

	for (i = 0; s[i] != NULL; i++)
	{
		free(s[i]);
	}
	free(s);
}

/**
 * _getenv - Entry point
 * @name: string dest
 * Description: 'Check if a character is uppercase'
 * Return: Always 0 (Success)
 */

char *_getenv(const char *name)
{
	int i, j, flag;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0, flag = 1; name[j] != '\0' && environ[i][j] != '\0'; j++)
		{
			if (name[j] != environ[i][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * print_string - Entry point
 * Description: 'fill the first n bytes of s with b'
 * @s: a pointer to a string
 * Return: Always 0 (Success)
 */

int print_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (1);
}
