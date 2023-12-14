#include "main.h"

/**
 * print_error - Displays the error message
 * @input: Input from user
 * @counter: Count of loops in shell
 * @argv: Arguments before program starts
 */

void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _prerror - prints the custom error
 * @argv: Arguments before program starts
 * @c: Count of error
 * @cmd: parsed command strings array
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * err_file - prints the custom error
 * @argv: Arguments before program starts
 * @c: Count of error
 */

void err_file(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
