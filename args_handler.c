#include "main.h"
/**
 * cmd_arg - returns commandline string arguments
 * @str: input from standard input / command line
 * Return: pointer to string arguments
 */
char **cmd_arg(char *str)
{
	char *temp, **token, *str3 = NULL, *str2 = NULL, delim[] = " \n";
	int i = 1, k = 0;

	str2 = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(str2, str);
	str3 = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(str3, str);
	temp = strtok(str3, delim);
	while (temp)
	{
		temp = strtok(NULL, delim);
		i++;
	}

	/* allocate memory and copy tokens to arguments array*/

	token = malloc(sizeof(char *) * i);
	temp = strtok(str2, delim);
	for (k = 0; k < (i - 1); k++)
	{
		token[k] = malloc(sizeof(char) * (_strlen(temp) + 1));
		_strcpy(token[k], temp);
		temp = strtok(NULL, delim);
	}
	token[i - 1] = NULL;

	/* free str2 */
	free(str2);
	free(str3);

	return (token);
}
