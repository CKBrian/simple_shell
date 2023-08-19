#include "main.h"
/**
 * com_path - returns pathname to command
 * @cmd_name: name of command
 * Return: pathname to command
 */
char *com_path(char *cmd_name)
{
	char *cmd, *path = "/bin/";


	cmd = malloc(sizeof(char) * (_strlen(cmd_name) + _strlen(path) + 1));
	if (cmd == NULL)
		perror("malloc in com_path failed\n");
	_strcpy(cmd, path);
	_strcat(cmd, cmd_name);

	return (cmd);
}
