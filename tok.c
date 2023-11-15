#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 * @str_input: input to be parsed
 * @delimiter: delimiter to be used (one character string)
 *
 * Return: array of tokens
 */

char **tokenizer(char *str_input, char *delimiter)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *track_ptr = NULL;

	token = _strtok_r(str_input, delimiter, &track_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delimiter, &track_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}
