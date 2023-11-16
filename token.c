#include "main.h"

/**
 * token - tokenizes string
 *@str: input to be parsed
 *@del: delimiter to be used
 *
 *Return: array of tokens
 */

char **token(char *str, char *del)
{
	int int_delimeter = 0;
	char **val = NULL;
	char *tok = NULL;
	char *store = NULL;

	tok = _tokstr(str, del, &store);

	while (tok != NULL)
	{
		val = _realloc(val, sizeof(*val) * int_delimeter, sizeof(*val) * (int_delimeter + 1));
		val[int_delimeter] = tok;
		tok = _tokstr(NULL, del, &store);
		int_delimeter++;
	}

	val = _realloc(val, sizeof(*val) * int_delimeter, sizeof(*val) * (int_delimeter+ 1));
	val[int_delimeter] = NULL;

	return (val);
}

/**
 *del_line - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void del_line(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *stdout - prints a string to stdout
 *@chan: channel to print out to
 *@str: string to be printed
 *
 *Return: void, return nothing
 */
void stdout(char *str, int chan)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		write(chan, &str[i], 1);
}

/**
 *copystr - copies a string to another buffer
 *@src: source to copy from
 *@dest: destination to copy to
 *
 * Return: void
 */

void _strcpy(char *src, char *dest)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 *strlength - counts string length
 *@string: string to be counted
 *
 * Return: length of the string
 */

int strlength(char *str)
{
	int length = 0;

	if (str == NULL)
		return (length);
	for (; str[length] != '\0'; length++)
		;
	return (length);
}
