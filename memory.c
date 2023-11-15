#include "shell.h"

/**
 * bfree - Deallocates memory for a pointer and sets the address to NULL.
 * @ptr: The address of the pointer to be deallocated.
 *
 * Return: 1 if memory is freed, otherwise 0.
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
