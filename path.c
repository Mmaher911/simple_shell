#include "main.h"

/**
 * path_cmd -  Search for executable command in path
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}
/**
 * build - Build the command
 * @tok: command that excutes
 * @val: Directory Command value
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *tok, char *val)
{
	char *cmd;
	size_t len;

	len = _strlen(val) + _strlen(tok) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, val);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, tok);

	return (cmd);
}
/**
 * _getenv - Gets the value of variable by name in environment
 * @name: variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
