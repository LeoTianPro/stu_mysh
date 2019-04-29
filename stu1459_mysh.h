/* Necessary header files */
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

#define MAX_PATH_LEN 1000 //Maximum path length
#define MAX_LINE 100      //Maximum filename length

char *grd[MAX_LINE]; // Save your input divided by spaces
int cmd_cnt;         // Save the subscript of grd[MAX_LINE]

void welcome();                          // Show welcome message and a brief intrduction of stu1459_mysh
void show_prompt();                      // Show terminal prompt
void get_command();                      // Get your input
void show_command_list();                // Show the command list
void show_command_doc();                 // Show the manul of command
void lclear();                           // Clear screen
void lls();                              // A simulation of "ls"(including hidden files and files in all subdirectories)
void lecho();                            // A simulation of "echo".
void lecho_redirect();                  //echo content can be redirected to file
void lpwd();                             // A simulation of "pwd"
void lcd();                              // A simulation of "cd"
void lmkdir();                           // A simulation of "mkdir"
void lrm();                              // A simulation of "rm"
void lcat();                             // A simulation of "cat"
void lwc();                              // A simulation of "wc"
void ltime();                            // Show current time
int match(const char *str1, char *str2); // A simulation of "strcmp()"