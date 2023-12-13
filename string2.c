#include "main.h"

/**
 * _puts - print string
 * @st: pointer to string
 * Return: void
 */
void _puts(char *st)
{
	int i;

	for (i = 0; st[i] != '\0'; i++)
	{
		_putchar(st[i]);
	}
	_putchar('\n');
}

/**
 * _strcmp - function compares two string
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if identical otherwise how much diffrent
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - function that check if c is alphabet
 * @c: character to check
 * Return: 1 if true 0 if false
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
