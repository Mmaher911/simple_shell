#include "ssh.h"

/**
 * _strlen - Counts the number of characters in a string.
 * @str: The string to count.
 * Return: The number of characters in the string.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int index, size;

	size = _strlen(dest);

	for (index = size; src[index - size] != '\0'; index++)
		dest[index] = src[index - size];
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string.
 **/
char *_strdup(char *str)
{
	char *strduplicate = NULL;
	int counter = 0, size = 0;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;

	/* Check malloc and free */
	strduplicate = malloc(size * sizeof(*str));
	if (strduplicate == NULL)
		return (NULL);

	for (; counter < size - 1; counter++)
		strduplicate[counter] = str[counter];

	strduplicate[counter] = '\0';
	return (strduplicate);
}

