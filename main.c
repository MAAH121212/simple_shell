#include "main.h"

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
		path = _strdup(_getenv("PATH"));
		line[_strlen(line) - 1] = '\0';
		args = strtow(line);

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
			continue;
		}

		fullPath = findInPATH(path, args[0]);
		if (!fullPath)
		{
			perror("./shell");
			free_args(args);
			free(path);
			continue;
		}

		free(args[0]);
		args[0] = fullPath;
		frk = fork();

		if (frk == 0)
		{
			execve(args[0], args, env);
			perror("./shell");
			free_args(args);
			free(fullPath);
			free(path);
			_exit(EXIT_FAILURE);
		}
		else if (frk == -1)
			perror("./shell");
		wait(&status);
		free_args(args);
		free(path);
	}
	return (0);
}
