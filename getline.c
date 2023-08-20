#include "main.h"
#define INIT_BUFFER_SIZE 1024
/**
 * _getline - get line from stdin
 * @size: size of initial buffer
 * @str: pointer to string output
 * @stream: input stream
 * Return: string pointer
 */
char *_getline(char *str, int *size, FILE *stream)
{

	int fdr, pos = 0;
	char st;

	*size = INIT_BUFFER_SIZE;
	(void)stream;
	str = malloc(sizeof(char) * (*size));
	if (!str)
	{
		return (NULL);
	}

	fflush(stdout);
	while (1)
	{
		fdr = read(STDIN_FILENO, &st, 1);

		(void)fdr;
		if (st == EOF || st == '\n')
		{
			str[pos] = '\0';
			return (str);
		}
		else
			str[pos] = st;
		/*reallocate memory*/
		if (pos >= INIT_BUFFER_SIZE)
		{
			*size += INIT_BUFFER_SIZE;
			str = realloc(str, (*size));
			if (str == NULL)
				return (NULL);
		}
		pos++;
	}
	return (str);

}
