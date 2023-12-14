#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* define */

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define DELIMITER " \t\r\n\a"
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct _builtin - singly linked list
 *
 * @command: a string
 * @function: points to the next node
 */

typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin_t;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct data - struct that contains all relevant data
 *@args: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@input: a string path for the current command
 *@environ: custom modified copy of environ from LL env
 *@pid: process ID of the shell
 *@fname: the program filename
 *@argc: the argument count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@counter: the error count
 *@env: linked list local copy of environ
 *@history: the history node
 *@alias: the alias node
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *args;
	char **argv;
	char *input;
	char **environ;
	char *pid;
	char *fname;
	int argc;
	int err_num;
	int linecount_flag;
	int env_changed;
	int status;
	unsigned int counter;
	list_t *env;
	list_t *history;
	list_t *alias;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/* string1.c */
char *_strncpy(char *des, char *sr, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);

/* string2.c */
void _puts(char *st);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);

/* string3.c */
void array_rev(char *ar, int ln);
int intlen(int nm);
char *_itoa(unsigned int n);

/* string4.c */
char *_strcat(char *des, char *sr);
char *_strcpy(char *des, char *sr);
char *_strchr(char *se, char ch);

/* string5.c */
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *st);
char *starts_with(const char *h, const char *n);

/* memory1.c */
void free_env(char **en);
void *fill_an_array(void *a, int e, unsigned int ln);
char *_memcpy(char *des, char *sr, unsigned int n);

/* memory2.c */
void *_calloc(unsigned int s);
void *_realloc(void *p, unsigned int o, unsigned int n);
void free_all(char **c, char *l);

/* input1.c */
char *_getline();
char *space(char *st);
char *enter(char *str);

/* input2.c */
void hashtag_handler(char *buf);
void prompt(void);
unsigned int check_delim(char c, const char *st);

/* input3.c */
char *_strtok(char *st, const char *del);
int history(char *i);
char **separator(char *input);

/* file_arg.c */
void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/* parsed_arg.c */
char **par_cmd(char *input);
int hand_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);

/* err.c*/
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void err_file(char **argv, int c);

/* env.c */
void create_env(char **env);
void free_envi(char **envi);

/* printf */
void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);

/* path.c */
int path_cmd(char **cmd);
char *build(char *tok, char *val);
char *_getenv(char *name);

/* help1.c */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/* help2.c */
void help_all(void);
void help_alias(void);
void help_cd(void);

/* help3.c */
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);

/* biultin1.c */
int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c,
		int stat);
int change_dir(char **cmd, __attribute__((unused))int st);

/* biultin2.c */
int dis_env(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);


#endif /*MAIN_H*/
