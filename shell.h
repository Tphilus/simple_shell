#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

/* Read/ Write */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* cmd chains */
#define CMD_CHAIN	3
#define CMD_AND		2
#define CMD_OR		1
#define CMD_NORM	0

/* Convert Numbs method */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 , getline method */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - sle linked list data structure
 * @num: the valuev of the area
 * @str:  stringe
 * @next:  next of the ..
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - pseudo-arguements to pass into a function,
 *		allowing for function for pointer struct
 *@arg: a strings generated from getline containing arguements
 *@argv: The array of strins generated from arg
 *@path: string path for the current command
 *@argc: It args count
 *@alias: was alias node
 *@env_changed: on the environ was changed
 *@status: the return status to the last exec'd command
 *@cmd_buf: address of the pointer to cmd_buf, on if chains
 *@line_count: It error counts
 *@err_num: the error code for exit()s
 *@linecount_flag: if count this input of the line
 *@fname: the program name of the file
 *@env: linked list copy of the evy
 *@environ: custom modified copy of environ from LL env
 *@history: the history code
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from read to input line
 *@histcount: the history numbs line
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer the chain buffer */
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - It contains a builtin strings
 *@type: builtin for cmd
 *@func: functs
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* fl toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void fork_cmd(info_t *);
void find_cmd(info_t *);

/* fl toem_parser.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);

/* fl loophsh.c */
int loophsh(char **);

/* fl toem_errors.c */
int _putfd(char c, int fd);
int _eputchar(char);
int _putsfd(char *str, int fd);
void _eputs(char *);

/* fl toem_string.c */
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);

/* fl toem_string1.c */
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);
char *_strdup(const char *);

/* Tll toem_exits.c */
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* fi toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* fi toem_realloc.c */
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);

/* toem_memory.c f1 */
int bfree(void **);

/* toem_atoi.c f1*/
int _atoi(char *);
int _isalpha(int);
int interactive(info_t *);
int is_delim(char, char *);

/*toem_errors1.c fl */
char *convert_number(long int, int, int);
int _erratoi(char *);
int print_d(int, int);
void remove_comments(char *);
void print_error(info_t *, char *);

/* toem_builtin.c f. */
int _myexit(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);

/* toem_builtin1.c f.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/* toem_getline.c f. */
ssize_t get_input(info_t *);
void sigintHandler(int);
int _getline(info_t *, char **, size_t *);

/*toem_getinfo.c f. */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* toem_environ.c f. */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int populate_env_list(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);

/* toem_getenv.c f. */
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);

/* toem_history.c f. */
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);


/* toem_lists.c f. */
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

/* toem_lists1.c */
char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t list_len(const list_t *);
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
int replace_alias(info_t *);
int replace_vars(info_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

#endif
