#include "main.h"
/**
 * help_exit - Displays information on the shell by exit command
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Displays information on the shell by help command
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help - display help builtin commands
 * @cmd: parsed command
 * @st: last command executed status
 * Return: 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		help_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		help_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		help_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		help_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
