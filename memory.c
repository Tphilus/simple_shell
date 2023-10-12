#include "shell.h"

/**
 * bfree - liberates the pointer, nullifies the address
 * @ptr: addy of the pointer to liberate
 *
 * Return: 1 ? free : 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

