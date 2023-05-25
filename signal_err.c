#include "shell.h"

/**
 * handle_signal - prints new line when CTRL + C is passed as input
 * @signal: sig name
 */
void handle_signal(int signal)
{
	char *prmpt = {"\n{^_^} "};
	(void) sig;

	write(STDOUT_FILENO, prmpt, _strlen(prmpt));
	fflush(stdout);
}

/**
 * _error - prints error output of a file
 * @argv: program name
 * @count: prompt number
 * @args: command to be put in
 * Return: success = 0
 */
int *_error(char *argv, int count, char *args)
{
	char *num;

	num = _itoa(count, 10);

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, num, _strlen(num));
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	perror(" ");

	return (0);
}

/**
 * _stat - get the file status
 * @cmd: pointer with commands
 * @path:  directory loaction
 * Return: success = 0
 **/
int _stat(char **cmd, char **path)
{
	char *conc_str = NULL, *new_concat = NULL;
	int count;

	struct stat sb;

	if (path == NULL)
	{
		f(path);
		f(cmd);
		return (0);
	}

	for (count = 0; path[count] != NULL ; count++)
	{
		conc_str = str_concat(path[count], "/");
		new_concat = str_concat(conc_str, cmd[0]);
		if (stat(new_concat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_concat;
			free(conc_str);
			free(path[0]);
			free(path);
			return (1);
		}
		f(conc_str);
		f(new_concat);
	}
	f(path[0]);
	f(path);
	return (0);
}

