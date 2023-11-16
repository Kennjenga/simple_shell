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
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");
			for (i = 0; commands[i] != NULL; i++)
			{
				command = tokenizer(commands[i], " ");
				if (command[0] == NULL)
				{
					free(command);
					break;
				}
				cmdtype = parse_command(command[0]);
				innitr(command, cmdtype);
				free(command);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
