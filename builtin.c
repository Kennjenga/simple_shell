#include "shell.h"

/**
 *envir - prints the current_environnement
 *@token - command entered
 *
 *Return: void
 */

void envir(char **token __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * exit - quit the shell
 * @token -  command entered
 *
 * Return: void
 */

void exit(char **token)
{
	int num_token = 0, arg;

	for (; token[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(token);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(token[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(token[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(token);
			free(commands);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
