#include "main.h"

/** parse_data- analyzing command
 * @cmd: command to be parsed
 *
 * Return: cmdtype
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
	
	path = check_path(cmd);
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
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmdtype == PATH_COMMAND)
	{
		if (execve(check_path(cmdtoken[0]), cmdtoken, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (cmdtype == INTERNAL_COMMAND)
	{
		f = get_func(cmdtoken[0]);
		f(cmdtoken);
	}
	if (cmdtype == INVALID_COMMAND)
	{
		print(shell_name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(cmdtoken[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
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
	char *p = _getenv("PATH");
	int i;

	if (p == NULL || _strlen(path) == 0)
		return (NULL);
	copy = malloc(sizeof(*copy) * (_strlen(p) + 1));
	_strcpy(p, copy);
	pat = tokenizer(copy, ":");
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
