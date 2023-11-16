#include "main.h"


/**
 *_tokstr - tokenizes a string
 *@str: string to be tokenized
 *@del: delimiter to be used to tokenize the string
 *@n_ptr: pointer to be used to keep track of the next token
 *
 *Return: (next token)
 */
char *_tokstr(char *str, char *del, char **n_ptr)
{
	char *end;

	if (str == NULL)
		str = *n_ptr;

	if (*str == '\0')
	{
		*n_ptr = str;
		return (NULL);
	}

	str += _strspn(str, del);
	if (*str == '\0')
	{
		*n_ptr = str;
		return (NULL);
	}

	end = str + _strcspn(str, del;
	if (*end == '\0')
	{
		*n_ptr = end;
		return (str);
	}

	*end = '\0';
	*n_ptr = end + 1;
	return (str);
}

/**
 * _atoi - changes string to an integer
 * @str: string to be changed
 *
 * Return:  int
 */
int _atoi(char *str)
{
	unsigned int x = 0;

	do {
		if (*str == '-')
			return (-1);
		else if ((*str < '0' || *str > '9') && *str != '\0')
			return (-1);
		else if (*str >= '0'  && *str <= '9')
			x = (x * 10) + (*str - '0');
		else if (x > 0)
			break;
	} while (*str++);
	return (x);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		tempk = malloc(new_size);
		return (temp);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp = malloc(new_size);
		if (temp != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp + i) = *((char *)ptr + i);
			free(ptr);
			return (temp);
		}
		else
			return (NULL);

	}
}

/**
 * exit_e - handles the signal raised by CTRL-C
 * @sig: signal number
 *
 * Return: void
 */
void exit_e(int sig)
{
	if (sig == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * toggle - ignores everything after a '#' 
 * @inp: input to be used
 *
 * Return: void
 */
void toggle(char *in)
{
	int i = 0;

	if (in[i] == '#')
		in[i] = '\0';
	while (in[i] != '\0')
	{
		if (in[i] == '#' && in[i - 1] == ' ')
			break;
		i++;
	}
	in[i] = '\0';
}
