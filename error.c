#include "ssh.h"

/**
 * err127 - Creates an error message for the error number 127.
 * @av: Array of command arguments.
 * @str_hist: String with the history number.
 * Return: A string with the error message, or NULL if memory allocation fails.
 */
char *err127(char **av, char *str_hist)
{
	char *error = NULL;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + _strlen(str_hist) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, str_hist);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": not found\n");

	return (error);
}

/**
 * err126 - Creates an error message for the error number 126.
 * @av: Array of command arguments.
 * @str_hist: String with the history number.
 * Return: A string with the error message, or NULL if memory allocation fails.
 */
char *err126(char **av, char *str_hist)
{
	char *error;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + _strlen(str_hist) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, str_hist);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": Permission denied\n");

	return (error);
}

/**
 * count_dig - Counts the number of digits in an integer.
 * @num: The integer to count.
 * Return: The number of digits.
 */
unsigned int count_dig(int num)
{
	unsigned int i = 0;

	for (; num > 0; i++)
		num = num / 10;

	return (i);
}

/**
 * str_num - Converts an integer to a string.
 * @n: The integer to convert.
 * Return: A string representation of the integer, or NULL if memory allocation fails.
 */
char *str_num(int n)
{
	unsigned int l_dig = count_dig(n);
	char *strn = NULL;
	int num = n;

	strn = malloc(sizeof(char) * (l_dig + 1));

	strn[l_dig] = '\0';

	l_dig--;
	do {
		strn[l_dig] = (num % 10) + '0';
		num /= 10;
		l_dig--;
	} while (num > 0);
	return (strn);
}
#include "ssh.h"

/**
 * prt_error - Prints the corresponding error message according to the error number.
 * @av: Array of command arguments.
 * @n_error: Error number.
 * Return: The error number.
 */
int prt_error(char **av, int n_error)
{
	char *msg_err = NULL; /* Error message */
	char *str_hist = NULL;

	str_hist = str_num(hist);

	/* Get message */
	switch (n_error)
	{
	case 126:
		msg_err = err126(av, str_hist);
		break;
	case 127:
		msg_err = err127(av, str_hist);
		break;
	case 2:
		if (!(_strcmp(av[0], "exit")))
			msg_err = err2_exit(av, str_hist);
		break;
	}

	/* Print error message */
	prt_stde(msg_err);

	if (str_hist)
		free(str_hist);

	if (msg_err)
		free(msg_err);

	return (n_error);
}

