#include "main.h"

/**
 * array_rev - function that reverse to an array
 * @ar: the array that reverse
 * @ln: array length
 */
void array_rev(char *ar, int ln)
{
	int i;
	char tmp;

	for (i = 0; i < (ln / 2); i++)
	{
		tmp = ar[i];
		ar[i] = ar[(ln - 1) - i];
		ar[(ln - 1) - i] = tmp;
	}
}

/**
 * intlen - function determine integer length
 * @nm: number of integers
 * Return: size of integer
 */
int intlen(int nm)
{
	int len = 0;

	while (nm != 0)
	{
		len++;
		nm /= 10;
	}
	return (len);
}

/**
 * _itoa - convert integer to character
 * @n: number of converted integers
 * Return: character pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}
