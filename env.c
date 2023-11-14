#include "shell.h"

/**
 * env - prints the current_environnement
 * @tokenized_command: command entered
 *
 * Return: void
 */

void env(char **tokenized_command __attribute__((unused)))
{
	unsigned int i, l;
	char newline = '\n';

	for (i = 0; environ[i] != NULL; i++)
	{
		l = _strlen(environ[i]);
		if (l != 0)
		{
			write(STDOUT_FILENO, environ[i], l);
			write(STDOUT_FILENO, &newline, 1);
		}
	}
}
