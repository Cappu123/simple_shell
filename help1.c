#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @ptr_size: size of ptr
 * @memo_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int ptr_size, unsigned int memo_size)
{
	void *new_block;
	unsigned int i;

	if (ptr == NULL)
	{
		new_block = malloc(memo_size);
		return (new_block);
	}
	else if (memo_size == ptr_size)
	return (ptr);
	else if (memo_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		new_block = malloc(memo_size);
		if (new_block != NULL)
		{
			for (i = 0; i < min(ptr_size, memo_size); i++)
			*((char *)new_block + i) = *((char *)ptr + i);
			free(ptr);
			return (new_block);
		}
		else
		return (NULL);

	}
}

/**
 * handle_ctrl_c - handles the signal raised by CTRL-C
 * @s_number: signal number
 *
 * Return: void
 */
void handle_ctrl_c(int s_number)
{
	if (s_number == SIGINT)
	write(STDIN_FILENO, "\n($) ", 5);
}

/**
 * ignore_comment - ignores everything after a '#' char
 * @input: the input
 *
 * Return: void
 */
void ignore_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
	input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
		break;
		i++;
	}
	input[i] = '\0';
}
