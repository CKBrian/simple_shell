#include <stdlib.h>
#include "main.h"
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to previous memory
 * @old_size: Size of old allocated space
 * @new_size: Size of new to be allocated space
 * Return: Pointer to new memory adress else NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *p;

	if (ptr == NULL)
	{
	p = malloc(new_size * sizeof(*p));
	if (p == NULL)
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size > old_size || new_size < old_size)
	{
		p = malloc(new_size * sizeof(*p));
		if (p == NULL)
		{
			free(p);
			return (NULL);
		}
		if (new_size < old_size)
		{
		for (i = 0; i < new_size; i++)
			p[i] = ((char *)ptr)[i];
		}
		else
		{
		for (i = 0; i < old_size; i++)
			p[i] = ((char *)ptr)[i];
		}
	}
	free(ptr);
	return (p);
}
