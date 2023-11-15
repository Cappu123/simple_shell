#include "shell.h"

/**
* execute_command - executes a command based on it's type
* @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
* @command_type: type of the command
*
* Return: void
*/
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		write(STDERR_FILENO, command_name, _strlen(command_name));
		write(STDERR_FILENO, ": 1: ", 6);
		write(STDERR_FILENO, tokenized_command[0], _strlen(tokenized_command[0]));
		write(STDERR_FILENO, ": not found\n", 13);
		status = 127;
	}
}
