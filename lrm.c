#include "stu1459_mysh.h"

void rm_dir(const char *pdir)
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat st;
    if (!(dp = opendir(pdir)))
    {
        perror(pdir);
        return;
    }
    chdir(pdir);
    while ((entry = readdir(dp)))
    {
        stat(entry->d_name, &st);
        if (__S_IFDIR & st.st_mode)
        {
            if ((strcmp(".", entry->d_name) == 0) || (strcmp("..", entry->d_name) == 0))
            {
                continue;
            }
            rm_dir(entry->d_name);
        }
        else
        {
            unlink(entry->d_name);
        }
    }
    chdir("..");
    rmdir(pdir);
    closedir(dp);
}

int rm(char *filename)
{
    char *filepath = filename;
    struct stat st;
    if (stat(filepath, &st) == 1)
    {
        return 1;
    }
    if (S_ISREG(st.st_mode))
    {
        if (unlink(filepath) == 1)
        {
            return 1;
        }
    }
    else if (S_ISDIR(st.st_mode))
    {
        if (filename == "." || filename == "..")
        {
            return 1;
        }
        rm_dir(filepath);
    }
    return 0;
}

void lrm()
{
    if (cmd_cnt < 2)
    {
        printf("rm: missing operand\n");
        return;
    }
    else
    {
        if ((match(grd[1], "-r") == 1) || (match(grd[1], "-R") == 1))
        {
            for (int i = 2; i < cmd_cnt; i++)
            {
                if (rm(grd[i]) == 1)
                {
                    perror(grd[i]);
                    continue;
                }
                printf("directory: %s has been removed\n", grd[i]);
            }
        }
        else
        {
            for (int i = 1; i < cmd_cnt; i++)
            {
                if (unlink(grd[i]) != 0)
                {
                    perror(grd[i]);
                    continue;
                }
                printf("%s has been removed\n", grd[i]);
            }
        }
        return;
    }
}
