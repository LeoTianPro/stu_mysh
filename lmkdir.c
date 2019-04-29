#include "stu1459_mysh.h"

void lmkdir()
{
    char newdir[MAX_LINE];
    if (cmd_cnt < 2)
    {
        printf("mkdir: missing operand\n");
        return;
    }
    else
    {
        for (int i = 1; i < cmd_cnt; i++)
        {
            strcpy(newdir, grd[i]);
            if (mkdir(newdir, 0755) != 0)
            {
                perror(newdir);
            }
        }
    }
}
