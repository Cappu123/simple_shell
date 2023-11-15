#include "shell.h"

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
/**
 * _strcspn - computes segment of string1 which consists of characters not in string2
 * @string1: string to be searched
 * @string2: string to be used
 *
 * Return: index at which a char in string1 exists in string2
 */

int _strcspn(char *string1, char *string2)
{
	int len = 0, i;
	
	for (i = 0; string1[i] != '\0'; i++)
	{
		if (_strchr(string2, string1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}
/**
 * _strchr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;
	
	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
