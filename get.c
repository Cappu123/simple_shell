#include "shell.h"

/**
* get_func - gets back a function based on the command given and a mapping
* @command: string to check against the mapping
*
* Return: pointer to the proper function, or null on fail
*/
void (*get_func(char *command))(char **)
{
	int i;
	elements_pair mapping[] = {
		{"env", env}, {"exit", quit}
	};
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}
/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_environment;
	char *pair_ptr;
	char *copy_name;
	
	for (my_environment = environ; *my_environment != NULL; my_environment++)
	{
		for (pair_ptr = *my_environment, copy_name = name;
				*pair_ptr == *copy_name; pair_ptr++, copy_name++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*copy_name == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}
