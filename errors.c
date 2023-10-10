#include "shell.h"

/**
 *_eputs - print the input of strinstrg
 * @str: string to print
 *
 * Return: empty [0]
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write the charac c to stderring (and return the way I want)
 * @c: charac that need to be printed
 *
 * Return: When it is successfull 1.
 * When crappy, -1 is returned, errno is a set correctly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - write the charac c to print fd
 * @c: It charac to be printed
 * @fd: filedescriptor take to write
 *
 * Return: When successful, 1.
 * When it full of crap, -1 is passed, while it errno is set properly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - It print input string
 * @str: string to print it
 * @fd: filedescriptor take to write
 *
 * Return:the numb of characs put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
