#include "shell.h"

/**
* _strtok_r - tokenizes a string
* @string: string to be tokenized
* @delim: delimiter to be used to tokenize the string
* @track_ptr: pointer to be used to keep track of the next token
*
* Return: The next available token
*/
char *_strtok_r(char *string, char *delim, char **track_ptr)
{
	char *end;

	if (string == NULL)
	string = *track_ptr;

	if (*string == '\0')
	{
		*track_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*track_ptr = string;
		return (NULL);
	}
	end = string + _strcspn(string, delim);
	if (*end == '\0')
	{
		*track_ptr = end;
		return (string);
	}

	*end = '\0';
	*track_ptr = end + 1;
	return (string);
}

/**
* _atoi - changes a string to an integer
* @s: the string to be changed
*
* Return: the converted int
*/
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
		return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
		return (-1);
		else if (*s >= '0'  && *s <= '9')
		n = (n * 10) + (*s - '0');
		else if (n > 0)
		break;
	} while (*s++);
	return (n);
}
