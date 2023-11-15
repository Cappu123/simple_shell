include "shell.h"

/**
 * _strcmp - compare two strings
 * @first: first string to be compared
 * @second: second string to be compared
 *
 * Return: difference of the two strings
 */

int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
		break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 * _strcat - concatenates two strings
 * @destination: string to be concatenated to
 * @source:  string to concatenate
 *
 * Return: address of the new string
 */
char *_strcat(char *destination, char *source)
{
	char *new_string =  NULL;
	int len_destin = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_destin + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_destin);
	new_string[len_destin + len_source] = '\0';
	return (new_string);
}
/**
 * _strspn - gets the length of a prefix substring
 * @string1: string to be searched
 * @string2: string to be used
 *
 * Return: number of bytes 
 */
int _strspn(char *string1, char *string2)
{
	int i = 0;
	int match = 0;

	while (string1[i] != '\0')
	{
		if (_strchr(string2, string1[i]) == NULL)
		break;
		match++;
		i++;
	}
	return (match);
}
