#include "main.h"
/**
 * stderr_dump - redirects stderr message to /dev/null
 * Return: nothing
 */
void stderr_dump(void)
{
	int fder;

	fder = open("/dev/null", O_WRONLY);
	if (dup2(fder, STDERR_FILENO) != -1)
		close(fder);
}
/**
 * get_input - gets and processes temp from temp stream
 * @env: environment variables
 * Return: 1 if input is absolute path to executable else 0
 */
input_t *get_input(char **env)
{
	char **arr_args = NULL, *args = NULL;
	int len = 10;
	input_t *temp;

		if (isatty(STDIN_FILENO))
		{
		if (write(STDOUT_FILENO, "($) ", _strlen("($) ")) == -1)
			exit(EXIT_FAILURE);
		}
		if (_getline(&args, &len, stdin) == 0)
		{
			stderr_dump();
			free(args);
			exit(98); }
		temp = malloc(sizeof(input_t));
		if (temp == NULL)
			return (NULL);
		arr_args = cmd_arg(args);
		if (arr_args == NULL)
		{
			perror("NULL input");
			free(temp);
			free(args);
			return (NULL);
		}
		temp->argv = arr_args;
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

