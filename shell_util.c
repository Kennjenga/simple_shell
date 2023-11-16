#include "main.h"

/**
 * _func - takes a func based on a commmand
 * @cmd: string to check against the mapping
 *
 * Return: (pointer to function)success else null 
 */
void (*_func(char *cmd))(char **)
{
	int i;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _getenv - env var value
 * @name: name of environment var
 *
 * Return: value of var -- success
 */
char *_getenv(char *n)
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
