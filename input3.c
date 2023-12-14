#include "main.h"

/**
 * _strtok - extracts tokens of a string
 * @st: string
 * @del: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *st, const char *del)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	if (st != NULL)
		new_token = st;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (check_delim(tokens[i], del) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + i;
	new_token = tokens;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (check_delim(new_token[i], del) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}

/**
 * history - write file
 * @i: input of user
 * Return: 0 on success -1 if failed
 */
int history(char *i)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (i)
	{
		while (i[len])
			len++;
		w = write(fd, i, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

/**
 * separator - Separates command by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used
 */

char **separator(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = _strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}
