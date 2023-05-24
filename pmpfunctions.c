#include "shell.h"

/**
 * thepromp - displaying the prompt
 */
void thepromp(void)
{
	PRINTER("$ ");
}
/**
 * print_error - Displaying Error Based on Command and How Many Time Shell Looped
 * @input:Input
 * @counter:Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

