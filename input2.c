#include "main.h"

/**
 * hashtag_handler - removes everything after '#'
 * @buf: input buffer
 * Return: Nothing
 */
void hashtag_handler(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && buf[i - 1] == ' ' && buf[i + 1] == ' ')
		{
			buf[i] = '\0';
		}
	}
}

/**
 * prompt - function that prints '$' to standard output
 */
void prompt(void)
{
	PRINT("$ ");
}

/**
 * check_delim - checks if a character matchs any character
 * @c: check character
 * @st: delimiters string
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char c, const char *st)
{
	unsigned int i;

	for (i = 0; st[i] != '\0'; i++)
	{
		if (c == st[i])
			return (1);
	}
	return (0);
}
