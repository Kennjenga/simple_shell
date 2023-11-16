#include "main.h"

/**
 *_strcmp - compare two strings
 *@stra: string to be compared
 *@strb:  string to be compared
 *
 * Return: (diff of strings) success
 */

int _strcmp(char *stra, char *strb)
{
	int i = 0;

	while (stra[i] != '\0')
	{
		if (stra[i] != strb[i])
			break;
		i++;
	}
	return (stra[i] - strb[i]);
}

/**
 *_strcat - concatenates two strings
 *@dest: string to be concatenated to
 *@src:  string to concatenate
 *
 * Return: (address of the new string) success
 */

char *_strcat(char *dest, char *src)
{
	char *new_string =  NULL;
	int len_dest = _strlen(dest);
	int len_src = _strlen(src);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_src + 1));
	_strcpy(dest, new_string);
	_strcpy(src, new_string + len_dest);
	new_string[len_dest + len_src] = '\0';
	return (new_string);
}

/**
 *_substr - gets length of a prefix substring
 *@s_search: searched string
 *@s_look: used string
 *
 *Return: number of bytes in the initial segment of 5 which are part of accept
 */

int _substr(char *s_search, char *s_look)
{
	int i = 0;
	int sim = 0;

	while (s_search[i] != '\0')
	{
		if (_getchar(s_look, s_search[i]) == NULL)
			break;
		sim++;
		i++;
	}
	return (sim);
}

/**
 *_search - looks for char not in another string
 *@s_searched: string searched
 *@s_look: string used
 *
 *Return: (index at which a char in str1 exists in str2) success
 */


int _search(char *s_searched, char *s_look)
{
	int len = 0, i;

	for (i = 0; s_searched[i] != '\0'; i++)
	{
		if (_getchar(s_look, s_searched[i]) != NULL)
			break;
		len++;
	}
	return (len);
}
/**
 *_getchar - gets  char in a string
 *@str: string to be searched
 *@chr: char to be checked
 *
 *Return: (pointer to the first occurence of chr in str) success
 */

char *_getchar(char *str, char chr)
{
	int i = 0;

	for (; str[i] != chr && str[i] != '\0'; i++)
		;
	if (str[i] == chr)
		return (str + i);
	else
		return (NULL);
}
