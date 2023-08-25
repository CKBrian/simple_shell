#include "main.h"
/**
 * path_find - Returns a 2d array with PATH variable
 * @env_p: environment variables
 * Return: NULL terminated 2d array
 */
char **path_find(char **env_p)
{
	int i, n = 0;
	char **path;

	/*find no of env variables*/
	while (env_p[n] != NULL)
	{
		n++;
	}
	/*allocate memory and copy env variables*/
	path = malloc(sizeof(char *) * (n + 1));
	for (i = 0; i < n; i++)
	{
		path[i] = malloc(sizeof(char) * (_strlen(env_p[i]) + 1));
		_strcpy(path[i], env_p[i]);
	}
	path[i] = NULL;

	return (path);
}
