#include "stu1459_mysh.h"

void lwc()
{
    int l = 0;
    int w = 0;
    int c = 0;
    int len = 0;
    int status = 0; //Check if the given character is a whitespace character
    int ltotal = 0;
    int wtotal = 0;
    int ctotal = 0;

    struct stat st;

    if (cmd_cnt < 2)
    {
        printf("mkdir: missing operand\n");
        return;
    }
    else
    {

        for (int i = 1; i < cmd_cnt; i++)
        {
            stat(grd[i], &st);
            if (S_ISDIR(st.st_mode))
            {
                perror(grd[i]);
                continue;
            }
            FILE *fp = fopen(grd[i], "r");
            if (!fp)
            {
                perror(grd[i]);
                continue;
            }

            fseek(fp, 0, SEEK_END); //Point to EOF.
            len = ftell(fp);        //Get the displacement of the current position relative to the beginning of the file, the displacement value is equal to the number of bytes in the file.
            rewind(fp);             //equal to "fseek(fp, 0, SEEK_CUR);"

            char *buf = (char *)malloc(len + 1); //Dynamically allocate memory space based on file size
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
            ltotal += l;
            wtotal += w;
            ctotal += c;

            printf("l=%d w=%d c=%d %s\n", l, w, c, grd[i]);
            fclose(fp);
        }
        if (cmd_cnt > 2)
            printf("l=%d w=%d c=%d %s\n", ltotal, wtotal, ctotal, "total");
    }
}
