#include "main.h"

/* exit, env, exit_status, cd, setenv, unsetenv, alias */

/**
  * _exiting - exiting shell
  * @cmd: struct pointer
  * Return: Nothing
  */

void _exiting(input_t *cmd)
{
	int status;

	if (_strncmp(cmd->argv[0], "exit", 4) == 0)
	{
		if (cmd->argv[1])
		{
			status = atoi(cmd->argv[1]);

	/*free struct elements, path element and cmd struct pointer*/
			if (cmd->pathFlag == 0)
				free(cmd->path);
			free_struct(cmd);
			free(cmd);

			exit(status);
		}

	/*free struct elements, path element and cmd struct pointer*/
	if (cmd->pathFlag == 0)
		free(cmd->path);
	free_struct(cmd);
	free(cmd);

	exit(EXIT_SUCCESS);
	}
}

/**
  * _env - prints the current environment
  * @cmd: pointer to a structure
  * @env_p: pointer to environment variables
  * Return: Nothing
  */

void _env(input_t *cmd, char **env_p)
{
	int i = 0;

	(void)cmd;
	while (env_p[i] != NULL)
	{
		write(STDOUT_FILENO, env_p[i], _strlen(env_p[i]));
		write(2, "\n", 1);
		i++;
	}
}

/**
  * _chdir - changes current directory
  * @cmd: pointer to a structure
  * Return: Nothing
  */
void _chdir(input_t *cmd)
{
	if (chdir(cmd->argv[1]) != 0)
		perror("Error: chdir failed\n");
}
/**
 * _setenv - Sets environment variables
 * @name: Name of the variable
 * @value: Value associated with the variable
 * @overwrite: if 0 then variable name is not changed
 * Return: 0 for success and -1 for success
 */
int _setenv(const char *name, const char *value, int overwrite)
{

}
/**
 * _unsetenv - Deletes environment variable
 * @name: name of environment variable
 * Return: 0 for success and -1 for failure
 */
int _unsetenv(const char *name)
{

}
