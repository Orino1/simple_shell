#include "shell.h"

/**
 * main - Simple Shell
 * @argc: Argument Cont
 * @argv:Argumen Value
 * Return: Exit Value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		reading_file(argv[1], argv);
	signal(SIGINT, handler);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			thepromp();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = command_parsed(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (check_builtins(cmd) == 0)
		{
			st = handle_builtins(cmd, st);
			free_the_whole_array(cmd, input);
			continue;
		}
		else
		{
			st = validat_command(cmd, input, counter, argv);

		}
		free_the_whole_array(cmd, input);
	}
	return (statue);
}
/**
 * check_builtins - validating builtin
 *
 * @cmd: comand
 * Return: 0 or -1
 */
int check_builtins(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * gene_array_env - generating Array of env Variable
 * @envi: Array of env Variable
 * Return: Void
 */
void gene_array_env(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

