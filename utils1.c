#include "main.h"

/**
*parse_data- analyzing command
* @cmd: command to be parsed
*
*Return: cmdtype
*/

int parse_data(char *cmd)
{
	int i;
	char *internal_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_cmd[i] != NULL; i++)
	{
		if (_strcmp(cmd, internal_cmd[i]) == 0)
			return (INTERNAL_COMMAND);
	}

	path = _ispath(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
* exe - executes a command
 * @cmdtoken: tokenized command
 * @cmdtype: type of  command
 *
 * Return: void
 */
void exe(char **cmdtoken, int cmdtype)
{
	void (*func)(char **cmd);

	if (cmdtype == EXTERNAL_COMMAND)
	{
		if (execve(cmdtoken[0], cmdtoken, NULL) == -1)
		{
			perror(_enviro("PWD"));
			exit(2);
		}
	}
	if (cmdtype == PATH_COMMAND)
	{
		if (execve(_ispath(cmdtoken[0]), cmdtoken, NULL) == -1)
		{
			perror(_enviro("PWD"));
			exit(2);
		}
	}
	if (cmdtype == INTERNAL_COMMAND)
	{
		f = _func(cmdtoken[0]);
		f(cmdtoken);
	}
	if (cmdtype == INVALID_COMMAND)
	{
		printout(shell_name, STDERR_FILENO);
		printout(": 1: ", STDERR_FILENO);
		printout(cmdtoken[0], STDERR_FILENO);
		printout(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * _ispath - is command in path
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *_ispath(char *command)
{
	char **pat = NULL;
	char *blc, *blc2, *copy;
	char *p = __enviro("PATH");
	int i;

	if (p == NULL || strlength(path) == 0)
		return (NULL);
	copy = malloc(sizeof(*copy) * (strlength(p) + 1));
	copystr(p, copy);
	pat = token(copy, ":");
	for (i = 0; pat[i] != NULL; i++)
	{
		blc2 = _strcat(pat[i], "/");
		blc = _strcat(blc2, command);
		if (access(blc, F_OK) == 0)
		{
			free(blc2);
			free(pat);
			free(copy);
			return (blc);
		}
		free(blc);
		free(blc2);
	}
	free(copy);
	free(pat);
	return (NULL);
}
