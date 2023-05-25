#include "shell.h"

/**
 * func_printenv - a function that prints the current environment
 * @environ: the environment variable
 */
void func_printenv(char **environ)
{
	int k = 0;

	for (; environ[k] ; k++)
		_puts(environ[k]);
}
