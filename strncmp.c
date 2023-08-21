#include "main.h"
/**
 * _strncmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * @n: number of chars to compare
 * Return: int
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i, diff = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0' ||
				s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
	}

	return (0);
}
