#include "shell.h"

/**
 * read_input - the function that stores whatever passes as standard input
 * Return: the string containing the input
 */
char *read_input(void)
{
	char *line = NULL;
	ssize_t sig;
	size_t buf = 0;
	int a;

	sig = getline(&line, &buf, stdin);
	if (!line)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (sig == 1)
	{
		free(line);
		return (NULL);
	}
	else if (signal == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	else
	{
		for (a = 0; line[a] == ' ' && line[a + 1] == ' '; a++)
			;
		if (!line[a] && line[a + 1] == '\n')
		{
			free(line);
			return (0);
		}
	}
	return (line);
}

/**
 * sparse_str - a function that divides a string to an array of strings
 * @line: string being separated
 * @env: environment variable
 * Return: tokens on success
 * or EXIT_FAILURE if fails
 */
char **sparse_str(char *line, char **env)
{
	int buf = TOK_BUFSIZE, posicion = 0;
	char **tok;
	char *t;

	if (line == NULL)
	{
		return (0);
	}
	tok = _calloc(sizeof(char *), buf);
	if (!tok)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	t = strtok(line, TOK_DELIM);
	while (t != NULL)
	{
		tok[posicion] = t;
		posicion++;
		t = strtok(NULL, TOK_DELIM);
	}
	if (tok[0] == NULL)
		tok[posicion] = "\n";

	/*Compare tokens[0]*/
	if ((_strcmp(tok[0], "exit") == 0) && tok[1] == NULL)
	{
		free(line); /*Free the memory and exit the program*/
		free(tokens);
		exit(0);
	}
	if ((_strcmp(tok[0], "env") == 0) && tok[1] == NULL)
		func_printenv(env);      /*find the environment*/

	return (tok);
}


/**
 * prompt - a function that prints '$' and waits for user input
 */
void prompt(void)
{
	char *prompt = {"{^_^} "};
	char *buf = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(buf);
}
