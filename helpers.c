#include "ssh.h"

/**
 * prt_stdo - Prints a string to the standard output.
 * @str: The string to print.
 */
void prt_stdo(char *str)
{
	unsigned int s_len;

	s_len = _strlen(str);
	write(STDOUT_FILENO, str, s_len);
}

/**
 * prt_stde - Prints a string to the standard error.
 * @str: The string to print.
 */
void prt_stde(char *str)
{
	unsigned int s_len;

	s_len = _strlen(str);
	write(STDERR_FILENO, str, s_len);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 * Return: The integer value of the string.
 */
int _atoi(char *s)
{
	int i, n, c;

	i = n = c = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '-')
			c++;
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			while (*(s + i) >= '0' && *(s + i) <= '9')
			{
				if (n == 0)
				{
					n = (n * 10) + (*(s + i) - '0');
					n *= -1;
				}
				else
					n = (n * 10) - (*(s + i) - '0');
				i++;
			}
			if (c % 2 == 0)
				n *= -1;
			return (n);
		}
		i++;
	}
	return (0);
}

