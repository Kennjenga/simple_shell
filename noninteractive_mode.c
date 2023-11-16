#include "main.h"

/**
 * non_interactive - doesn’t interact with the user.
 *
 * Return: void
 */

void non_interactive(void)
{
	char **command = NULL;
	int i, cmdtype = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
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
		exit(status);
	}
}
