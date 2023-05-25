#include "shell.h"

/**
 * _which - a function that identifies the path of the command
 * @foundpath: command that is being passed
 * Return: complete path of the command or 0 on failure
 */
char **_which(char *foundpath)
{
	int s = TOK_BUFSIZE, j = 0;
	char *copy_path = NULL, *tok = NULL, *sparse = ":=";
	char **dir = _calloc(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}
	if (dir == NULL)
	{
		free(foundpath);
		perror("Error allocated memory");
		return (NULL);
	}

	copy_path = _strdup(foundpath); /*copiar el string --> palabra PATH*/
	tok = strtok(copy_path, sparse); /*separar el string por un separador*/
	while (tok != NULL)
	{
		dir[j] = tok;
		j++;
		tok = strtok(NULL, sparse);
	}

	return (dir);
}


/**
 * child_process - a function that executes a command if the path is an
 * executable file
 * @args: command to be executed
 * @env: a function that environment variable
 * @status_main: the status variable
 * @av: program name
 * @cnt: the count of prompt
 * Return: 1
 */
int child_process(char **av, char **args, char **env, int status_main, int cnt)
{
	pid_t pid;
	int s;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], cnt, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status_main == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &s, WUNTRACED);
	}
	return (1);
}

/**
 * search_path - a function that gets the path to execute commands
 * @environ: the Environment variable
 * Return: the token_path
 **/
char **search_path(char **environ)
{
	int pos = 0;
	char **token_path;

	for (; environ[position] != NULL ; pos++)
	{
		if (environ[pos][0] == 'P' && environ[pos][2] == 'T')
		{
			token_path = _which(environ[pos]);
		}
	}
	return (token_path);
}
