#include "shell.h"

/**
 * main - a function that creates a prompt that reads input
 * @ac: the number of arguemnets
 * @av: the array of arguements
 * @env: the environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *l;
	char **args, **p;
	int count = 0, s = 0;
	(void) av;
	signal(SIGINT, handle_signal);
	while (1)
	{
		prompt();
		l = read_input()
		args = sparse_str(l, env);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			count += 1;
			p = search_path(env); /*look for PATH in the environment variable*/
			s = _stat(args, p);
			child_process(av, args, env, s, count);
		}
		else
		{
			free(args);
		}
		free(l);
	}
	return (EXIT_SUCCESS);
}
