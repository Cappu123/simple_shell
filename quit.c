#include "shell.h"

/**
* quit - exits the shell
* @tokenized_command: command entered
*
* Return: void
*/

void quit(char **tokenized_command)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
	;
	if (num_token == 1)
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			write(STDERR_FILENO, command_name, _strlen(command_name));
			write(STDERR_FILENO, ":1: exit:Incorrect number: ", 27);
			write(STDERR_FILENO, tokenized_command[1], _strlen(tokenized_command[1]));
			write(STDERR_FILENO, "\n", 1);
		}
		else
		{
			free(line);
			free(tokenized_command);
			free(commands);
			exit(arg);
		}
	}
	else
	write(STDERR_FILENO, "$: no more arguments\n", 23);
}
