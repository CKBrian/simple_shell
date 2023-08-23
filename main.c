#include "main.h"
/**
 * exec_section - implements a simple shell
 * @cmd: pointer to a struct
 * @av: program arguments
 * Return: Nothing
 */
void exec_section(input_t *cmd, char **av)
{
	pid_t pid1;
	int i;

	pid1 = fork();
	if (pid1 > 0)
		wait(NULL);
	if (pid1 == 0)
	{
		if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
		{
			/*bin/sh: 1: qwerty: not found*/
			write(2, av[0], _strlen(av[0]));
			write(2, ": 1: ", 5);
			for (i = 0; cmd->argv[i] != NULL; i++)
			{
				write(2, cmd->argv[i], _strlen(cmd->argv[i]));
			}
			write(2, ": not found\n", _strlen(": not found\n"));
			/*free resources*/
			free_struct(cmd);
			if (cmd->pathFlag == 0)
				free(cmd->path);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * main - implements a simple shell
 * @ac: argument count
 * @av: arguments array
 * @envp: environment variables
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av, char **envp)
{
	input_t *cmd;

	(void)ac;
	(void)av;

	while (1)
	{
		cmd = get_input(envp);
		if (cmd == NULL)
			continue;
		_exiting(cmd);
		if (_strncmp(cmd->argv[0], "env", 3) == 0)
			_env(cmd, envp);
		else if (_strncmp(cmd->argv[0], "cd", 2) == 0)
		{
			_chdir(cmd);
		}
		else
			exec_section(cmd, av);

		/*free(args);*/
		free_struct(cmd);
		if (cmd->pathFlag == 0)
			free(cmd->path);
		free(cmd);
	}

	return (EXIT_SUCCESS);
}
