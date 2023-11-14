#include "shell.h"

/**
 * File_name: main.c file
 *
 * Auth: Cappy Alemayehu
 * Project: 0x16. C - Simple Shell
 *
 * Description:
 * Function(main) The main shell program
 * 
 */

/**
 * main - the main shell
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in helpers, implements EOF, prints error on failure
 * Return: 0 on success
*/
int main(int argc __attribute__((unused)), char **argv)
{
	char **commands, **current_command = NULL;
	char *line = NULL;
	char *command_name = NULL;
	int status, i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, handle_ctrl_c);
	command_name = argv[0];

	while (1)
	{
		non_interactive();
		write(STDOUT_FILENO, " ($) ", 8);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		remove_newline(line);
		ignore_comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			/* initializer -   */
			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
}
