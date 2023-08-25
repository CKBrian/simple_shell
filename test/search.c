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
	char *path, *temp, *dir_name;

	path = _getenv("PATH");
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
				return (temp);
			}
		}
		closedir(dir);
		}
		temp = strtok(NULL, ":");
	}

	return (name);
}
