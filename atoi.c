#include <limits.h>
#include "main.h"
/**
 * _atoi - Converts a string to a character
 * @s: String to be converted
 * Return: number/integer
 */

int _atoi(char *s)
{
	int i, num = 0, flag = 1, lbreak = 0, k = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
		{

			if (s[i] == '+' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
				i++;
			else if (s[i] == '-')
			{
				k++;
				if (k % 2 != 0)
					flag = -1;
				else
					flag = 1; }
			while (s[i] >= '0' && s[i] <= '9')
			{
				num += s[i] - '0';
				if (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					num *= 10;
					if (num == 2147483640 && s[i + 1] == '8' && flag == -1)
						return (INT_MIN); }
				else if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				{
					lbreak = 1;
					i++;
					break; }
				i++; }

		}
		if (lbreak == 1)
		{
			break;
		}
	}
	num *= flag;
	return (num);
}
