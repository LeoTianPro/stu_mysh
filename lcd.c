#include "stu1459_mysh.h"

void lcd()
{
	struct passwd *pwd = NULL;
	char pathname[MAX_PATH_LEN];
	pwd = getpwuid(getuid());
	if (cmd_cnt == 1)
	{
		strcpy(pathname, pwd->pw_dir);
		if (chdir(pathname) != 0)
		{
			perror(pathname);
		}
	}
	else
	{
		if (chdir(grd[1]) != 0)
		{
			perror(grd[1]);
		}
	}
}
