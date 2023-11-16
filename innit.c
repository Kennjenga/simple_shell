#include "main.h"

/**
 * innit - innitializes everything
 * @command: try to check current token
 * @cmdtype: parse token
 *
 * Return: void function
 */

void innit(char **command, int cmdtype)
{
	pid_t PID;

	if (cmdtype == EXTERNAL_COMMAND || cmdtype == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(command, cmdtype);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(command, cmdtype);
}
