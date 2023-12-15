#include "ssh.h"

/**
 * count_lim - Counts the number of times a separator character appears in a string.
 * @line: The string to count.
 * @limit: The separator character.
 * Return: The number of separations.
 */
unsigned int count_lim(char *line, const char *limit)
{
	int i; /* Runner */
	int contsp = 0; /* Counter for limit */
	int csp; /* Consecutive limit */

	for (i = 0 ; line[i] != '\0'; i++)
	{
		for (csp = 0; line[i] == limit[0]; i++)
			csp++;
		if (line[i] != '\0' && csp > 0 && (i - 1) > csp)
		{
			contsp++;
			i--;
		}
	}
	return (contsp);
}

/**
 * get_array - Gets an array of command arguments from a line of command.
 * @line: The line of command.
 * Return: An array of command arguments.
 */
char **get_array(char *line)
{
	const char limit[] = " ";
	int i; /* Runner */
	int contsp = 0; /* Counter for limit */
	char **array = NULL;

	/* Count limit characters */
	contsp = count_lim(line, limit);
	/* Allocate memory */
	array = malloc(sizeof(char *) * (contsp + 2));
	if (!array)
		return (NULL);

	/* Fill array */
	array[0] = strtok(line, limit);
	if (!array[0])
	{
		free(array);
		return (NULL);
	}

	for (i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
		if (!array[i])
		{
			free(array);
			return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

