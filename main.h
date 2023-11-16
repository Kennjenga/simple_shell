#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct dict -  maps a command name to a function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct dict
{
	char *command_name;
	void (*func)(char **command);
} mapper;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*string methods*/
int _substr(char *, char *);
int _strcmp(char *, char *);
char *_getchar(char *, char);
char *_strcat(char *, char *);
int _search(char *, char *);

/*tokens*/
void stdout(char *, int);
char **token(char *, char *);
void del_line(char *);
int strlength(char *);
void copystr(char *, char *);

/*handlers*/
char *_tokstr(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void exit_e(int);
void toggle(char *);

/*utils*/
int parse_data(char *);
void exe(char **, int);
char *_ispath(char *);

/*built_in*/
void envir(char **);
void exit(char **);

/*shell_utils*/
void (*_func(char *))(char **);
char *_enviro(char *);

/*non_interactivemode*/
extern void non_interactive(void);

/*initializer*/
extern void innit(char **current_command, int type_command);

#endif /*MAIN_H*/
