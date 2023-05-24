#include "shell.h"

/**
 * handle_builtins - Handle Builtin Command
 * @cmd: command parsed
 * @er:statue previeuse exu
 * Return: -1 or 0
 */

int handle_builtins(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * validat_command - Excute a Command
 *
 * @cmd: the command
 * @input: input from user
 * @c: excu time case
 * @argv: name of the program
 * Return: 1 or -1 or 0
 */
int validat_command(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			command_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * handler - Handle the condition ^C
 * @signal: Captured Signal
 * Return: Void
 */
void handler(int signal)
{
	if (signal == SIGINT)
	{
		PRINTER("\n$ ");
	}
}

