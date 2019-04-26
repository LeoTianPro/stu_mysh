#include "stu1459_mysh.h"

void show_dir(char *pathname)
{
	DIR *dir = NULL;
	struct dirent *dp = NULL;
	struct stat statbuf;
	int cnt = 0;

	if (!(dir = opendir(pathname)))
	{
		perror(pathname);
		return;
	}

	if (pathname != ".")
		printf("\n%s:\n", pathname);
	else
		printf("\n");

	while ((dp = readdir(dir)))
	{
		stat(dp->d_name, &statbuf);
		if (strcmp(".", dp->d_name) == 0 ||
			strcmp("..", dp->d_name) == 0)
			continue;

		if (S_ISDIR(statbuf.st_mode))
			printf("\e[34m%-20s\e[0m", dp->d_name); //If it is a directory, it shows blue.
		else
			printf("%-20s", dp->d_name);

		cnt++;
		if (cnt % 5 == 0)
			printf("\n");
	}
	printf("\n\n");
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
		show_dir(pathname);
}
