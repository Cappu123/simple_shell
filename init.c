#include "shell.h"

/**
 * initializer - starts executing everything
 * @current_token: try to check current token
 * @type_token: parse token
 *
 * Return: void function
 */

void initializer(char **current_token, int type_token)
{
	pid_t PID;

	if (type_token == EXTERNAL_COMMAND || type_token == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
		execute_command(current_token, type_token);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
	execute_command(current_token, type_token);
}
