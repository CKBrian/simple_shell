#ifndef MAIN_H
#define MAIN_H

/*Libraries*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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

/*prototypes*/
input_t *get_input(char **env);
char **cmd_arg(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *com_path(char *cmd_name);
char **path_find(char **env_p);
void free_struct(input_t *f);
int _strncmp(char *s1, char *s2, int n);

#endif /* MAIN_H */
