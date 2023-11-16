#include "main.h"

/**
 * _func - takes a func based on a commmand
 * @cmd: string to check against the hash
 *
 * Return: (pointer to function)success else null
 */
void (*_func(char *cmd))(char **)
{
	int i;
	mapper hash[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd, hash[i].command_name) == 0)
			return (hash[i].func);
	}
	return (NULL);
}

/**
 * _enviro - env var value
 * @n: name of environment var
 *
 * Return: value of var -- success
 */
char *_enviro(char *n)
{
	char **env;
	char *sim;
	char *n_copy;

	for (env = environ; *env != NULL; env++)
	{
		for (sim = *env, n_copy = n;
		     *sim == *n_copy; sim++, n_copy++)
		{
			if (*sim == '=')
				break;
		}
		if ((*sim == '=') && (*n_copy == '\0'))
			return (sim + 1);
	}
	return (NULL);
}
