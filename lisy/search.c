#include "main.h"
#include <dirent.h>
/**
 * com_search - searcher for the directory the given command is located in
 * @name: name of program to search
 * Return: full path to the directory containing the program
 */
char *com_search(char *name)
{
	struct dirent *entry;
	DIR *dir;
	char *path, *path2, *temp, *dir_name;

	path2 = _getenv("PATH");
	path = malloc(sizeof(char) * (_strlen(path2) + 1));
	_strcpy(path, path2);
	temp = strtok(path, ":");
	while (temp != NULL)
	{
		dir = opendir(temp);
		if (dir != NULL)
		{
		while ((entry = readdir(dir)) != NULL)
		{
			dir_name = entry->d_name;
			if (_strncmp(name, dir_name, _strlen(dir_name)) == 0)
			{
				closedir(dir);
				free(path);
				return (temp);
			}
		}
		closedir(dir);
		}
		temp = strtok(NULL, ":");
	}
	free(path);

	return (name);
}
