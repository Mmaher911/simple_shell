#include "ssh.h"

/**
 * execute - Execute a command that can be either builtin or external.
 * @av: Array of command arguments
 * @l_ret: Pointer to the last return value
 * Return: The return value of the executed command
 */
int execute(char **av, int *l_ret)
{
	int i;
	builtin b_arr[] = {
		{"exit", b_exit},
		{"env", b_env},
		{NULL, NULL}};

	for (i = 0; b_arr[i].fname; i++)
	{
		if (_strcmp(b_arr[i].fname, av[0]) == 0)
			break;
	}
	if (b_arr[i].fun != NULL)
	{
		b_arr[i].fun(av, l_ret);
		return (*l_ret);
	}
	return (exc_ext(av));
}
