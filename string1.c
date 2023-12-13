#include "main.h"

/**
 * _strncpy - string copying
 * @des: string destination
 * @sr: string source
 * @n: charaters to be copied
 * Return: copied strings
 */

char *_strncpy(char *des, char *sr, int n)
{
	int i = 0;

	while (i < n && *(sr + i))
	{
		*(des + i) = *(sr + i);
		i++;
	}
	while (i < n)
	{
		*(des + i) = '\0';
		i++;
	}
	return (des);
}

/**
 * _strlen - counts string length
 * @s: string
 * Return: string length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _putchar - writes the character to stdout
 * @c: print character
 * Return: character to standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - convert string to an integer
 * @s: string
 * Return: converted integer
 */

int _atoi(char *s)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}
