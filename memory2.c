#include "main.h"

/**
 * _calloc - allocates memory for array using malloc
 *@s: size
 *Return: void
 */
void *_calloc(unsigned int s)
{
	char *a;
	unsigned int i;

	if (s == 0)
	return (NULL);
	a = malloc(s);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < s; i++)
	{
		a[i] = '\0';
	}
	return (a);
}

/**
 * _realloc -  reallocates memory blocked using malloc and free
 *@p: pointer
 *@o: the old size of pointer
 *@n: the new size of pointer
 *Return: return Pointer to reallocated memory
 */
void *_realloc(void *p, unsigned int o, unsigned int n)
{
	void *result;

	if (n == o)
		return (p);
	if (n == 0 && p)
	{
		free(p);
		return (NULL);
	}
	result = malloc(n);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (p == NULL)
	{
		fill_an_array(result, '\0', n);
		free(p);
	}
	else
	{
		_memcpy(result, p, o);
		free(p);
	}
	return (result);
}

/**
 * free_all - free all memory allocated
 * @c: pointer array
 * @l: pointer character
 * Return: Void
 */
void free_all(char **c, char *l)
{
	free(c);
	free(l);
	c = NULL;
	l = NULL;
}
