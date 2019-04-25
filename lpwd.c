#include "stu1459_mysh.h"

void lpwd()
{
	char pathname[MAX_PATH_LEN];
	if (!getcwd(pathname, MAX_PATH_LEN))
		perror(pathname);
	printf("%s\n", pathname);
}
