#include "main.h"
/**
 * *_strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @dest: Destination string
 * @src: Source string.
 * Return: Dest
 */
char *_strcpy(char *dest, char *src)
{
	int length;
	int i, j = 0;

	for (i = 0; src[i] != '\0'; i++)
	{}

	length = i + 1;

	/* copy the string from src[] to the dest[] array */
	for (j = 0; j < length; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
