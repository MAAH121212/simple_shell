#include "main.h"

/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{

    ssize_t lineSize = 0;
    size_t len = 0;
    char *line = NULL, *path = NULL, *fullPath;
    char **args = NULL;
    int frk;
    int status;
    
    while(1)
    {   
        if (isatty(STDIN_FILENO))
            print_string("#cisfun$ ");

        if (getline(&line, &len, stdin) == -1)
        {
            free(line);
            if (isatty(STDIN_FILENO))
                _putchar('\n');
            return(0);
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
                free_args(args); free(path); free(line);
                exit(EXIT_SUCCESS);
            }
            free_args(args); free(path);
            continue;
        }

        fullPath = findInPATH(path, args[0]);
        if (!fullPath)
        {
            print_string("./shell: No such file or directory\n");
            free_args(args); free(path); 
            continue;
        }
        
        free(args[0]);
        args[0] = fullPath;
        frk = fork();
        if (frk == 0)
        {
            execve(args[0], args, env);
            perror("./shell");
            free_args(args); free(fullPath); free(path);
            _exit(EXIT_FAILURE);
        }    
        else if (frk == -1)
        {
            perror("./shell");
        }
        wait(&status);
        free_args(args); free(path);
    } 
    return (0);
}
