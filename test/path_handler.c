#include "main.h"
/**
 * path_find - Returns a 2d array with PATH variable
 * @env_p: environment variables
 * Return: NULL terminated 2d array
 */
char **path_find(char **env_p)
{
	int i;
	char path[] = "PATH";

	for (i = 0; env_p[i] != NULL; i++)
	{
		if (_strncmp(env_p[i], path, 4))
		{
			return (cmd_arg(env_p[i]));
		}
	}
	return (NULL);
}
