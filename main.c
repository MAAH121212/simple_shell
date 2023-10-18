#include "main.h"

/**
 * builtins - check for builtins
 * @args: array of strings
 * @path: path
 * @line: line
 * Description: builtins
 * Return: 0
 */

int builtins(char **args, char *path, char *line)
{
	if (get_op_func(args[0]) != NULL)
	{
		if (get_op_func(args[0])() == 2)
		{
			free_args(args);
			free(path);
			free(line);
			exit(EXIT_SUCCESS);
		}
		free_args(args);
		free(path);
		return (1);
	}
	return (0);
}

/**
 * found - check if prog exists
 * @args: array of strings
 * @path: path
 * @fullPath: fullpath
 * Description: program found
 * Return: 0
 */

int found(char **args, char *path, char *fullPath)
{
	if (!fullPath)
	{
		perror("./shell");
		free_args(args);
		free(path);
		return (0);
	}
	return (1);
}

/**
 * main - stat example
 * @ac: number of args
 * @av: args
 * @env: envs
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	size_t len = 0;
	char *line = NULL, *path = NULL, *fullPath;
	char **args = NULL;
	int frk, status;

	while (ac || !ac || av || !av)
	{
		if (isatty(STDIN_FILENO))
			print_string("#cisfun$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			return (0);
		}
		if (!(_strlen(line) - 1))
			continue;
		path = _strdup(_getenv("PATH")), line[_strlen(line) - 1] = '\0';
		args = strtow(line), fullPath = findInPATH(path, args[0]);
		if (builtins(args, path, line))
			continue;
		if (!found(args, path, fullPath))
			continue;
		free(args[0]);
		args[0] = fullPath, frk = fork();
		if (frk == 0)
		{
			execve(args[0], args, env);
			perror("./shell");
			free_all(args, fullPath, path);
			_exit(EXIT_FAILURE);
		}
		else if (frk == -1)
			perror("./shell");
		wait(&status);
		free_all(args, path, NULL);
	}
	return (0);
}
