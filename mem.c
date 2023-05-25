#include "shell.h"

/**
 *_calloc -allocated memory for nmeb element the sizee bytes
 *@nmemb: number of element in array
 *@size: bytes for each position in array
 *Return: pointer void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *t;
	unsigned int j;

	if (nmemb == 0 || size == 0)
		return (NULL);

	t = malloc(nmemb * size);
	if (t == NULL)
		return (NULL);

	for (j = 0; j < nmemb * size; j++)
		t[j] = 0;

	return (t);

}
