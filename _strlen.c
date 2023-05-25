#include "shell.h"

/**
 *_puts - a function that prints a string
 *@str: pointer to an int that will be updated
 *
 *Return: void
 */
void _puts(char *str)
{
	int m;

	for (m = 0 ; str[m] != '\0' ; m++)
	{
		_putchar(str[m]);
	}
	_putchar('\n');
}

/**
 * _strlen - a function that returns a string
 * @s: integer used
 * Return: string length
 */
int _strlen(const char *s)
{
	int j;

	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	return ((j + 1));
}

/**
 * _putchar - writes character c to stdout
 * @c: character to be print
 *
 * Return: success = 1.
 * error -1 is returned, and errno set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *str_concat - a pointer to array
 *@s1: Array two
 *@s2: Array one
 *Return: Always an array dinamic
 */
char *str_concat(char *s1, char *s2)
{
	char *dst;
	unsigned int j, k, size;

	/*If the array is empty*/
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*count size total*/
	size = (_strlen(s1) + _strlen(s2) + 1);

	/*malloc*/
	dst = (char *) malloc(size * sizeof(char));

	if (dst == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (j = 0; *(s1 + j) != '\0'; j++)
		*(dst + j) = *(s1 + j);

	for (k = 0; *(s2 + k) != '\0'; k++)
	{
		*(dst + j) = *(s2 + k);
		j++;
	}
	dst[j] = '\0';

	return (dst);
}

/**
 * _strcmp - function that compares two strings
 * @s1: string1
 * @s2: string2
 * Return: returns an integer <,  equal  to,  or
 * > than zero if s1 is found, respectively, to be
 * <, to match, or be > than s2
 */
int _strcmp(char *s1, char *s2)
{
	char *q1 = s1;
	char *q2 = s2;

	while (*q1 != '\0' && *q2 != '\0' && *q1 == *q2)
	{
		q1++;
		q2++;
	}
	return (*q1 - *q2);
}

