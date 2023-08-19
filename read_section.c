#include "main.h"
/**
 * get_input - gets and processes temp from temp stream
 * @env: environment variables
 * Return: 1 if input is absolute path to executable else 0
 */
input_t *get_input(char **env)
{
	char *args = NULL;
	size_t len = 0;
	input_t *temp;

		if (write(STDOUT_FILENO, "($) ", _strlen("($) ")) == -1)
			perror("Error: Write failed\n");
		if (getline(&args, &len, stdin) == -1)
		{
			perror("Error: getline failed or EOF\n");
			free(args);
			exit(98);
		}

		temp = malloc(sizeof(input_t));
		if (temp == NULL)
			return (NULL);
		temp->argv = cmd_arg(args);
		/*if (_strncmp("/", args, 1) == 0)*/
		if (args[0] == '/')
		{
			temp->path = temp->argv[0];
			temp->pathFlag = 1;
		}
		else
		{
			temp->pathFlag = 0;
			temp->path = com_path(temp->argv[0]);
		}
		temp->envp = path_find(env);
		free(args);

		return (temp);
}

