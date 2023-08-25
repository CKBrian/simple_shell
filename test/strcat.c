#include "main.h"
/**
 * _strcat - Appends 'src' string to 'dest' string
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, k;

	/* find the terminator */
	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	/* Append text */
	for (k = 0; src[k] != '\0'; k++)
	{
		dest[i] = src[k];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
