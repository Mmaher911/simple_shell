#include "main.h"

/**
 * par_cmd - Parses command recieved from stdin
 * @input: gathered string from stdin
 * Return: Parsed strings to be used
 */

char **par_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}

/**
 * hand_builtin - predefine builtin commands
 * @cmd: parsed command strings
 * @st: last execution status
 * Return: -1 Failure 0 Success
 */

int hand_builtin(char **cmd, int st)
{
	builtin_t built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * check_cmd - commands excuted found in predefined path
 * @cmd: parsed command strings
 * @input: Input recieved from user
 * @c: Shell Excution of Command that Not Found
 * @argv: Arguments before program starts
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */

int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}

/**
 * signal_to_handle - Configures ^C not to terminate the shell
 * @sig: Incoming Signal
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
