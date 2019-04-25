#include "stu1459_mysh.h"

void lwc()
{
    int l = 0;
    int w = 0;
    int c = 0;
    int len = 0;
    int status = 0;

    if (cmd_cnt < 2)
    {
        printf("mkdir: missing operand\n");
        return;
    }
    else
    {
        for (int i = 1; i < cmd_cnt; i++)
        {
            FILE *fp = fopen(grd[i], "r");
            if (fp == NULL)
            {
                printf("stu1459_mysh: file can't open");
            }

            fseek(fp, 0, SEEK_END);
            len = ftell(fp);
            rewind(fp);

            char *buf = (char *)malloc(len + 1);
            fread(buf, len, 1, fp);

            for (int j = 0; buf[j]; j++)
            {
                c++;
                if (buf[j] == '\n')
                {
                    l++;
                }
                if (!isspace(buf[j]) && status == 0)
                {
                    w++;
                    status = 1;
                }
                else if (isspace(buf[j]))
                {
                    status = 0;
                }
            }

            printf("l=%d w=%d c=%d %s\n", l, w, c, grd[i]);

            free(buf);
            fclose(fp);
        }
    }
}
