#include "shell.h"

/**
 * check_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *check_path(char *command)
{
	char **i_path = NULL;
	char *concat, *concat2, *copy_path;
	char *path = _getenv("PATH");

	int i;

	if (path == NULL || _strlen(path) == 0)
	return (NULL);
	copy_path = malloc(sizeof(*copy_path) * (_strlen(path) + 1));
	_strcpy(path, copy_path);
	i_path = tokenizer(copy_path, ":");
	for (i = 0; i_path[i] != NULL; i++)
	{
		concat2 = _strcat(i_path[i], "/");
		concat = _strcat(concat2, command);
		if (access(concat, F_OK) == 0)
		{
			free(concat2);
			free(i_path);
			free(copy_path);
			return (concat);
		}
		free(concat);
		free(concat2);
	}
	free(copy_path);
	free(i_path);
	return (NULL);
}
