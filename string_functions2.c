#include "shell.h"

/**
 * _strcspn - computes segment of string1
 * which consists of characters not in string2
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
