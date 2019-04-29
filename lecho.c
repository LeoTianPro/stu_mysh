#include "stu1459_mysh.h"

void lecho()
{
	char *command = NULL;
	char environment[MAX_PATH_LEN];

	for (int i = 1; i < cmd_cnt; i++)
	{
		command = grd[i];
		if (command[0] == '$')
		{
			strcpy(environment, command + 1);
			char *buff = getenv(environment);
			if (buff)
				printf("%s\n", buff);
			else
				printf("\n");
		}
		else
			printf("%s ", grd[i]);
	}
	printf("\n");
}
