#include "main.h"
/**
 * exec_section - implements a simple shell
 * @cmd: pointer to a struct
 * Return: Nothing
 */
void exec_section(input_t *cmd)
{
	pid_t pid1;

	pid1 = fork();
	if (pid1 > 0)
		wait(NULL);
	if (pid1 == 0)
	{
		if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
			perror("execve: failed\n");
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
		_exiting(cmd);
		exec_section(cmd);

		/*free(args);*/
		free_struct(cmd);
		if (cmd->pathFlag == 0)
			free(cmd->path);
		free(cmd);
	}

	return (EXIT_SUCCESS);
}
