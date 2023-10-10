#include "shell.h"

/**
 **_strncpy - copy the strings
 *@dest: destination of string obviously
 *@src: IT src string
 *@n: amounts of the characs copy
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - It concatenate two strings
 *@dest: string in one
 *@src: string in two
 *@n: amount of the bytes max
 *Return: It concatenated strings
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, i;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - It locates a characs into strings
 *@s: string helps to parse
 *@c: charac helps to locate
 *Return: (s) it pointer to mems location s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
