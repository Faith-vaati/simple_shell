#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * prompt - call prompt from another function (prompt)
 *
 **/
void prompt(void)
{
	for (;;)
	{
		char *text = NULL, **environ;
		pid_t child_pid;
		int status, lenbuf;
		size_t bufsize = 0;

		place("$ ");
		lenbuf = getline(&text, &bufsize, stdin);
		if (lenbuf == -1)
			free(text);
			exit(98);
		if (compareExit(text, "exit") == 0)
			free(text);
			exit(0);
		if (compareEnv(text, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmpdir(*environ, "USER")) ||
						!(_strcmpdir(*environ, "LANGUAGE")) ||
						!(_strcmpdir(*environ, "SESSION")) ||
						!(_strcmpdir(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*environ, "SHLV")) ||
						!(_strcmpdir(*environ, "HOME")) ||
						!(_strcmpdir(*environ, "C_IS")) ||
						!(_strcmpdir(*environ, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*environ, "LOGNAME")) ||
						!(_strcmpdir(*environ, "TERM")) ||
						!(_strcmpdir(*environ, "PATH")))
				{
					place(*environ), place("\n"); }
				environ++; }}
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		free(text);
		if (child_pid == 0)
			identify_string(text);
		free(text);
		else
			wait(&status);
		free(text);
	}}
