#include "main.h"

/**
 * _strncmp - function to compares the number of characters of two strings
 * @s1: 1st string
 * @s2: 2nd string
 * @n: number of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strdup - string duplication
 * @st: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *st)
{
	size_t len, i;
	char *st2;

	len = _strlen(st);
	st2 = malloc(sizeof(char) * (len + 1));
	if (!st2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		st2[i] = st[i];
	}
	return (st2);
}

/**
 * starts_with - checks if string starts with haystack
 * @h: string to search
 * @n: the string to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *h, const char *n)
{
	while (*n)
		if (*n++ != *h++)
			return (NULL);
	return ((char *)h);
}
