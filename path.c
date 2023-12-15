#include "ssh.h"

/**
 * _getenv - Search a value of an environment variable.
 * @name: Name of environment variable.
 * Return: A pointer to the value.
 */
char *_getenv(char *name)
{
	unsigned int i = 0; /* Runner */
	char *value = NULL;
	int found = 1; /* Boolean True = 0 */
	unsigned int len = 0;

	if (!name)
		return (NULL);

	len = _strlen(name);

	while (environ[i] != NULL)
	{
		/* Compare */
		found = _strncmp(environ[i], name, len);
		/* If value is found */
		if (found == 0)
		{
			value = environ[i] + len;
			value = _strdup(value);
			if (value && _strlen(value))
				return (value);
			free(value);
			return (NULL);
		}
		i++;
	}
	/* If value isn't found */
	return (NULL);
}

/**
 * _create_path - Create a linked list with the directories of the path.
 * Return: A pointer to the head of the list.
 */
lpath *_create_path(void)
{
	char *value = NULL;
	char *word = NULL;
	lpath *head = NULL;

	value = _getenv("PATH=");
	if (!value || *value == '\0')
		return (NULL);

	if (value[0] == ':')
		add_node_end(&head, "./");

	/* Fill list */
	word = strtok(value, ":");
	for (; word;)
	{
		add_node_end(&head, word);
		word = strtok(NULL, ":");
	}
	free(value);
	return (head);
}

/**
 * _getpath - Get complete path of the command.
 * @argv: Array of command arguments.
 * Return: A string with the complete path.
 */
char *_getpath(char **argv)
{
	lpath *head_path = NULL, *temp = NULL;
	char *path = NULL;
	struct stat buf;
	int len = 0;

	/* If the input is a complete path */
	if ((argv[0][0] == '/' || argv[0][0] == '.') &&
	    stat(argv[0], &buf) == 0)
	{
		path = _strdup(argv[0]);
		return (path);
	}
#include "ssh.h"

/**
 * _getpath - Gets the complete path of the command.
 * @argv: Array of command arguments.
 * Return: A string with the complete path.
 */
char *_getpath(char **argv)
{
	lpath *head_path = NULL, *temp = NULL;
	char *path = NULL;
	struct stat buf;
	int len = 0;

	/* If the path is not complete */
	len = _strlen(argv[0]);
	head_path = _create_path();
	for (temp = head_path; temp != NULL && argv[0][0] != '.';
	     temp = temp->next)
	{
		path = malloc(sizeof(char) * (temp->len + len + 2));
		if (!path)
			break;
		_strcpy(path, temp->dir);
		_strcat(path, "/");
		_strcat(path, argv[0]);
		if (stat(path, &buf) == 0)
		{
			free_list(head_path);
			return (path);
		}
		else
		{
			free(path);
			path = NULL;
		}
	}
	if (head_path)
		free_list(head_path);
	return (NULL);
}

