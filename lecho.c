#include "stu1459_mysh.h"

void lecho()
{
	for (int i = 1; i < cmd_cnt; i++)
	{
		printf("%s ", grd[i]);
	}
	printf("\n");
}
