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
