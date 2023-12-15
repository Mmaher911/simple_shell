#include "ssh.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if the strings are the same.
 */
int _strcmp(char *s1, char *s2)
{
	for (; (*s1 != '0' && *s2 != '\0') && *s1 == *s2;)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _strncmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: The number of bytes of the strings to compare.
 * Return: > 0 if s1 < s2, 0 if s1 = s2, > 0 if s1 > s2.
 */
int _strncmp(char *s1, char *s2, int n)
{

	int c;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (c = 0; (s1[c] != '\0' || s2[c] != '\0') && c < n; c++)
	{
		if (s1[c] > s2[c])
			return (s1[c] - s2[c]);
		else if (s1[c] < s2[c])
			return (s1[c] - s2[c]);
	}
	return (0);
}
