#include "stu1459_mysh.h"

int i;

void print_file(int fd)
{
	char buf;
	while (read(fd, &buf, sizeof(char)) != 0)
		printf("%c", buf);    
	if (i != cmd_cnt - 1)
		printf("\n\n");
	else
		printf("\n");
}

void lcat()
{
	int fd;
	struct stat st;

	if (cmd_cnt < 2)
	{
		printf("stu1459_mysh: please input at least one filename\n");
		return;
	}
	else
	{
		for (i = 1; i < cmd_cnt; i++)
		{
			if ((fd = open(grd[i], O_RDONLY)) == -1)
			{
				perror(grd[i]);
				continue;
			}
			stat(grd[1], &st);
			if (S_ISDIR(st.st_mode))
			{
				printf("cat: %s: Is a directory\n", grd[1]);
				continue;
			}
			else
				print_file(fd);
		}
	}

	close(fd);
}
