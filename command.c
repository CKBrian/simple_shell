#include "main.h"
/**
 * com_sort - sorts command names
 * @name: name of command
 * Return: path to the respective command program
 */
char *com_sort(char *name)
{
	char *temp = NULL, cwd[1024], *cmd_name, *cmd = NULL;

	temp = getcwd(cwd, sizeof(cwd));
	temp = malloc(sizeof(char) * (_strlen(cwd) + 1));
	if (temp == NULL)
		return (NULL);
	_strcpy(temp, cwd);
	cmd_name = strtok(name, ".~/");

	/*generate full path to command executable*/
	cmd = malloc(sizeof(char) * (_strlen(name) + _strlen(temp) + 2));
	if (cmd != NULL)
	{
		_strcpy(cmd, temp);
		_strcat(cmd, "/");
		_strcat(cmd, cmd_name);
		_strcat(cmd, "\0");
	}
	free(temp);
	return (cmd);
}
/**
 * com_path - returns pathname to command
 * @cmd_name: name of command
 * Return: pathname to command
 */
char *com_path(char *cmd_name)
{
	char *cmd, *path = "/bin/";

	if (_strncmp(cmd_name, "./", 2) == 0)
	{
		return (com_sort(cmd_name));
	}

	cmd = malloc(sizeof(char) * (_strlen(cmd_name) + _strlen(path) + 1));
	if (cmd == NULL)
		perror("malloc in com_path failed\n");
	_strcpy(cmd, path);
	_strcat(cmd, cmd_name);

	return (cmd);
}
