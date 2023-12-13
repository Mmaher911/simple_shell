#include "main.h"

/**
 * free_env - Frees memory of created enviroment variables
 * @en:  Environment variables array
 */

void free_env(char **en)
{
	int i;

	for (i = 0; en[i]; i++)
	{
		free(en[i]);
	}
}

/**
 * fill_an_array - fill an array by certain number of bytes
 *@a: void pointer
 *@e: intiger
 *@ln: length for intiger
 *Return: void pointer
 */
void *fill_an_array(void *a, int e, unsigned int ln)
{
	char *p = a;
	unsigned int i = 0;

	while (i < ln)
	{
		*p = e;
		p++;
		i++;
	}
	return (a);
}

/**
 * _memcpy - copy bytes of memory to destination from source
 *@des: pointer destination
 *@sr: pointer source
 *@n: number
 *Return: pointer to destination
 */
char *_memcpy(char *des, char *sr, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		des[i] = sr[i];
	}
	return (des);
}
