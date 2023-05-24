#include "shell.h"
/**
 * reading_file - reading cmd from a file
 * @filename: file name
 * @argv: program name
 * Return: -1 or  0
 */

void reading_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		validat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * validat_file - validating Command in Line of File
 * @line: Line From File
 * @counter: error number
 * @fp: file D
 * @argv: Name of the program
 * Return : VOID
 */
void validat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = command_parsed(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			case_of_file(cmd, line, fp);
		}
		else if (check_builtins(cmd) == 0)
		{
			st = handle_builtins(cmd, st);
			free(cmd);
		}
		else
		{
			st = validat_command(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * case_of_file - exiting case
 * @line: buffer from a file
 * @cmd: the command
 * @fd: File D
 * Return : VOID
 */
void case_of_file(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}

