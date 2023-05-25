#include "shell.h"

/**
 * _strdup - a function that copyies a string to another
 * @str: the array
 * Return: pointer of the sting copied
 */
char *_strdup(char *str)
{
	int j, k;
	char *s = NULL;

	if (str == NULL)
		return (0);
	for (j = 0; str[j]; j++)
		;
	j++;
	s = malloc(j * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0; j < j; k++)
	{
		s[k] = str[k];
	}
	return (s);
}

/**
 * _itoa - the integer to ascii
 * @num: num
 * @base: base
 * Return: char
 **/
char *_itoa(int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long o = num;

	if (num < 0)
	{
		o = -num;
		sign = '-';
	}
	ptr = &buff[49];
	*ptr = '\0';

	do      {
		*--ptr = array[o % base];
		o /= base;
	} while (o != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
