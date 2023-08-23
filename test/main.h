#ifndef MAIN_H
#define MAIN_H

/* Externs */

extern char **environ;

/*Libraries*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/*structs*/

/**
 * struct input - struct for execve arguments
 * @argv: command arguments
 * @path: command pathname
 * @envp: command environment variables
 * @pathFlag: command pathname flag
 */

typedef struct input
{
	char **argv;
	char **envp;
	char *path;
	int pathFlag;
} input_t;

/**
 * struct env_list - list of environment variables
 * @next: pointer to the nnext node
 * @name: Name of environment variable
 * @value: value of the variable
 * @overwrite: permission to overwrite
 *

typedef struct env_list
{
	char *name;
	char *value;
	int overwrite;
	list_e *next;
} list_e;

*prototypes*/

input_t *get_input(char **env);
char **cmd_arg(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *com_path(char *cmd_name);
char **path_find(char **env_p);
void free_struct(input_t *f);
int _strncmp(char *s1, char *s2, int n);
void _exiting(input_t *cmd);
void _env(input_t *cmd, char **env_p);
void _chdir(input_t *cmd);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **str, int *size, FILE *stream);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);

#endif /* MAIN_H */