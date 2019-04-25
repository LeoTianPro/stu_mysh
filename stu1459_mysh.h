#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <signal.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1000
#define MAX_LINE 100

char *grd[MAX_LINE]; // Save your input divided by spaces.
int cmd_cnt;         // Save the subscript of grd[MAX_LINE].

void showShell();                        // Show terminal prompt.
void getCommand();                       // Get your input.
void lclear();                           // Clear screen
void lls();                              // A simulation of "ls"(including hidden files and files in all subdirectories).
void lecho();                            // A simulation of "echo".
void lpwd();                             // A simulation of "pwd".
void lcd();                              // A simulation of "cd".
void lrm();                              // A simulation of "rm".
void lcat();                             // A simulation of "cat".
void lwc();                              // A simulation of "wc".
void lmkdir();                           // A simulation of "mkdir".
int match(const char *str1, char *str2); // A simulation of "match".