#include "main.h"

/**
* _getline - read input from standard input
* Return: the input on a buffer
*/
char *_getline()
{
	int i, rd, buffsize = BUFSIZE;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (i >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}

/**
 * space - Modifies the input string to remove whitespaces
 * @st: modifies input
 * Return: Returns modified string
 */
char *space(char *st)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(st) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; st[i] == ' '; i++)
		;
	for (; st[i + 1] != '\0'; i++)
	{
		buff[j] = st[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * enter - Handles newline input
 * @str: String to handle
 * Return: Empty string
 */
char *enter(char *str)
{
	free(str);
	return ("\0");
}
