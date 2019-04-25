#include "stu1459_mysh.h"

void show_dir(char *pathname)
{
	DIR *dir = NULL;
	struct dirent *dp = NULL;
	int cnt = 0;

	if ((dir = opendir(pathname)) == NULL)
	{
		perror(pathname);
		return;
	}
	printf("%s:\n", pathname);
	while ((dp = readdir(dir)) != NULL)
	{
		if (strcmp(".", dp->d_name) == 0 ||
			strcmp("..", dp->d_name) == 0)
			continue;
		printf("%-20s ", dp->d_name);
		cnt++;
		if (cnt % 5 == 0)
			printf("\n");
	}
	printf("\n");
	if (dir != NULL)
		closedir(dir);
}
void lls()
{
	char *pathname = ".";

	if (cmd_cnt >= 2)
	{
		for (int i = 1; i < cmd_cnt; i++)
		{
			pathname = grd[i];
			show_dir(pathname);
			if (i != cmd_cnt - 1)
				printf("\n");
		}
	}
	else
	{
		show_dir(pathname);
	}
}
