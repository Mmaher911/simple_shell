#include "main.h"

/**
 * _strcat - function to concatenates two strings
 * @des: 1st string
 * @sr: 2nd string
 * Return: first string + second string
 */
char *_strcat(char *des, char *sr)
{
	char *s = des;

	while (*des != '\0')
	{
		des++;
	}

	while (*sr != '\0')
	{
		*des = *sr;
		des++;
		sr++;
	}
	*des = '\0';
	return (s);
}

/**
 * _strcpy - function to copy string
 * @des: destination
 * @sr: source
 * Return: to destination
 */
char *_strcpy(char *des, char *sr)
{
	int i = 0;

	while (sr[i])
	{
		des[i] = sr[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

/**
 * _strchr - locates the character of a string
 * @se: search for string
 * @ch: character
 * Return: pointer to character
 */
char *_strchr(char *se, char ch)
{
	do {
		if (*se == ch)
		{
			break;
		}
	} while (*s++);
	return (se);
}
