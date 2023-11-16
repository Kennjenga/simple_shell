#include "main.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **command = NULL;
	int i, cmdtype = 0;
	size_t n = 0;

	sig(SIGINT, exit_e);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		printout(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			del_line(line);
			toggle(line);
			commands = token(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			command = token(commands[i], " ");
			if (command[0] == NULL)
			{
				free(command);
				break;
			}
			cmdtype = parse_data(command[0]);
			innit(command, cmdtype);
			free(command);
		}
		free(commands);
	}
	free(line);

	return (status);
}
