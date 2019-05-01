/***************************************************************************
*Project Name: stu159_mysh
*Description: a simple simulation of Linux shell implemented by C
*Auther：Titanlbr520
*Last Modified： 2019.5.1
*Github repository:	https://github.com/Titanlbr520/stu_mysh
***************************************************************************/

#include "stu1459_mysh.h"

int main()
{
	int go_on = 1;

	welcome();
	sleep(1);

	while (go_on)
	{
		/** Display terminal prompt **/
		show_prompt();

		/** Get input and transfer it to command **/
		get_command();

		/** Execute the command based on your input **/
		if (is_command())
		{
			continue;
		}
	}

	return 0;
}

void welcome()
{
	char *welcome = "\n\
			\e[35mHi! This is a simple simulation of Linux shell!\e[0m\n\
			\e[35mIf you really like my project, you can star it on https://github.com/Titanlbr520/stu_mysh .\e[0m\n\
			\e[35mAnd I sincerely expect your suggestions.\e[0m \n\n\
			\e[33mInput 'man' to show the command list or 'man [command]' to show a certain command.\e[0m\n\n";

	printf("%s", welcome);
}

void show_prompt()
{
	/* The terminal prompt consists of: [username +@+hostname+current directory]+user prompt */

	uid_t uid;
	char *ret = NULL;
	struct passwd *user = NULL;
	char hostname[100];
	char cwd[MAX_PATH_LEN];

	/* Get user id */
	uid = getuid();

	/* Get the user's passwd structure according to uid */
	user = getpwuid(uid);
	printf("\e[34m[%s@\e[0m", user->pw_name); // Print username

	/* Get the host name */
	gethostname(hostname, 100);
	printf("\e[34m%s\e[0m:", hostname); // Print host name

	/* Get the current working directory */
	getcwd(cwd, 120);
	if (strcmp(cwd, user->pw_dir) == 0)
	{
		printf("~"); // Home directory special handling
	}
	else
	{
		ret = strrchr(cwd, '/'); // Get the last directory of the path
		if (ret[1] == '\0')
		{
			printf("/]"); // Root directory
		}
		else
		{
			printf("\e[34m%s]\e[0m", ret + 1);
		}
	}

	/* Print user prompt */
	if (0 == uid)
	{
		printf("\e[34m#\e[0m "); // Root
	}
	else
	{
		printf("\e[34m$\e[0m "); // General user
	}

	fflush(stdout); // Refresh the terminal prompt
}

void get_command()
{
	cmd_cnt = 0;
	char str[MAX_LINE]; // Save your original input
	char *next = NULL;
	memset(grd, 0, MAX_LINE);
	fgets(str, 80, stdin);
	if (str[strlen(str) - 1] == '\n')
	{
		str[strlen(str) - 1] = '\0';
	}
	next = strtok(str, " ");
	while (next != NULL)
	{
		grd[cmd_cnt] = (char *)malloc(sizeof(*next));
		strcpy(grd[cmd_cnt++], next);
		next = strtok(NULL, " ");
	}
}

int is_command()
{
	if (NULL == grd[0]) //If there is no command (just press "enter")
	{
		return 0;
	}
	else if (strcmp(grd[0], "clear") == 0)
	{
		lclear();
	}

	else if (strcmp(grd[0], "ls") == 0)
	{
		lls();
	}

	else if (strcmp(grd[0], "echo") == 0)
	{
		for (int i = 1; i < cmd_cnt; i++)
		{
			if (strcmp(grd[i], ">") == 0 || strcmp(grd[i], ">>") == 0)
			{
				lecho_redirect();
				return 1;
			}
		}
		lecho();
		return 1;
	}

	else if (strcmp(grd[0], "cat") == 0)
	{
		lcat();
	}

	else if (strcmp(grd[0], "mkdir") == 0)
	{
		lmkdir();
	}

	else if (strcmp(grd[0], "rm") == 0)
	{
		lrm();
	}

	else if (strcmp(grd[0], "cd") == 0)
	{
		lcd();
	}

	else if (strcmp(grd[0], "pwd") == 0)
	{
		lpwd();
	}

	else if (strcmp(grd[0], "wc") == 0)
	{
		lwc();
	}

	else if (strcmp(grd[0], "time") == 0)
	{
		ltime();
	}

	else if (strcmp(grd[0], "sh") == 0)
	{
		welcome();
	}

	else if (strcmp(grd[0], "man") == 0)
	{
		if (grd[1])
			show_command_doc(grd[1]);
		else
		{
			show_command_list();
		}
	}

	else if (strcmp(grd[0], "exit") == 0 || strcmp(grd[0], "quit") == 0)
	{
		printf("\n\
			\e[35mThanks for your use, good bye~\e[0m\n\n");
		sleep(1);
		exit(0);
	}

	else
	{
		printf("stu1459_mysh: command not found: %s\n", grd[0]);
	}
}

void show_command_list()
{
	char *commondlist[] = {
		"\n",
		"COMMAND                                        FUNCTION\n",
		"\e[33mls [FILE]...\e[0m                                   list directory contents",
		"\e[33mecho [STRING/$ENVIRON]...\e[0m                                           display a line of text or environment variable",
		"\e[33mcat [FILE]...\e[0m                                  concatenate files and print on the standard output",
		"\e[33mmkdir DIRECTORY...\e[0m                             make directories",
		"\e[33mrm [-r/-R] [FILE]...\e[0m                           remove files or directories",
		"\e[33mcd DIRECTORY\e[0m                                   go to the given directory",
		"\e[33mpwd\e[0m                                            print name of current/working directory",
		"\e[33mwc [FILE]...\e[0m                                   print newline, word, and byte counts for each file",
		"\e[33mexit/quit\e[0m                                      cause normal process termination",
		"\e[33mman [command]\e[0m                                  show the manul of command",
		"\e[33mclear\e[0m                                          clear the terminal screen",
		"\e[33msh\e[0m                                  	       show some information of stu1459_mysh",
		"\e[33mtime\e[0m                                  	       show current time\n"};

	for (int i = 0; i < sizeof(commondlist) / sizeof(commondlist[i]); i++)
	{
		printf("%s\n", commondlist[i]);
	}
}

void show_command_doc()
{

	/** Manual for each command **/
	char *ls_doc = "\nls [FILE]... - list directory contents\n\n";
	char *echo_doc = "\necho [STRING/$ENVIRON]... - display a line of text or environment variable\n\n";
	char *cat_doc = "\ncat [FILE]... - concatenate files and print on the standard output\n\n";
	char *mkdir_doc = "\nmkdir DIRECTORY... - make directories\n\n";
	char *rm_doc = "\nrm [-r/-R] [FILE]... - remove files or directories\n\n";
	char *cd_doc = "\ncd - go to the given directory\n\n";
	char *pwd_doc = "\npwd - print name of current/working directory\n\n";
	char *wc_doc = "\nwc [FILE]... - print newline, word, and byte counts for each file\n\n";
	char *exit_doc = "\nexit/quit - cause normal process termination\n\n";
	char *man_doc = "\nman [command] - show the manul of command\n\n";
	char *clear_doc = "\nclear - clear the terminal screen\n\n";
	char *sh_doc = "\nsh - show some information of stu1459_mysh\n\n";
	char *time_doc = "\ntime - show current time\n\n";

	if (strcmp(grd[1], "ls") == 0)
	{
		printf("%s", ls_doc);
	}
	else if (strcmp(grd[1], "echo") == 0)
	{
		printf("%s", echo_doc);
	}
	else if (strcmp(grd[1], "cat") == 0)
	{
		printf("%s", cat_doc);
	}
	else if (strcmp(grd[1], "mkdir") == 0)
	{
		printf("%s", mkdir_doc);
	}
	else if (strcmp(grd[1], "rm") == 0)
	{
		printf("%s", rm_doc);
	}
	else if (strcmp(grd[1], "cd") == 0)
	{
		printf("%s", cd_doc);
	}
	else if (strcmp(grd[1], "pwd") == 0)
	{
		printf("%s", pwd_doc);
	}
	else if (strcmp(grd[1], "wc") == 0)
	{
		printf("%s", wc_doc);
	}
	else if (strcmp(grd[1], "exit") == 0 || strcmp(grd[1], "quit") == 0)
	{
		printf("%s", exit_doc);
	}
	else if (strcmp(grd[1], "man") == 0)
	{
		printf("%s", man_doc);
	}
	else if (strcmp(grd[1], "clear") == 0)
	{
		printf("%s", clear_doc);
	}
	else if (strcmp(grd[1], "sh") == 0)
	{
		printf("%s", sh_doc);
	}
	else if (strcmp(grd[1], "time") == 0)
	{
		printf("%s", time_doc);
	}
	else
	{
		printf("No manual entry for %s\n", grd[1]);
	}
}

void lclear()
{
	printf("\033[2J"); //clear.
	printf("\033[H");  //move the mouse to a proper positoin.
}

void ltime()
{
	int weekday;
	int month;
	time_t tvar;
	struct tm *tp = NULL;
	time(&tvar);
	tp = localtime(&tvar); //Get local time
	weekday = tp->tm_wday;
	switch (weekday)
	{
	case 1:
		printf("Mon ");
		break;
	case 2:
		printf("Tues ");
		break;
	case 3:
		printf("Wed ");
		break;
	case 4:
		printf("Thur ");
		break;
	case 5:
		printf("Fri ");
		break;
	case 6:
		printf("Sat ");
		break;
	case 7:
		printf("Sun ");
		break;
	default:
		break;
	}
	month = 1 + tp->tm_mon; //Must add 1 after reviewing the data: tm_mon is one less than the actual value
	switch (month)
	{
	case 1:
		printf("Jan ");
		break;
	case 2:
		printf("Feb ");
		break;
	case 3:
		printf("Mar ");
		break;
	case 4:
		printf("Apr ");
		break;
	case 5:
		printf("May ");
		break;
	case 6:
		printf("Jun ");
		break;
	case 7:
		printf("Jul ");
		break;
	case 8:
		printf("Aug ");
		break;
	case 9:
		printf("Sep ");
		break;
	case 10:
		printf("Oct ");
		break;
	case 11:
		printf("Nov ");
		break;
	case 12:
		printf("Dec ");
		break;
	default:
		break;
	}
	printf("%d ", tp->tm_mday);
	printf("%d:", tp->tm_hour);
	printf("%d:", tp->tm_min);
	printf("%d ", tp->tm_sec);
	printf("CST ");						//CST, it means "China Standard Time"
	printf("%d\n", 1900 + tp->tm_year); //Must be added 1900, the returned value is not a complete year, less than the actual value of 1900
}

void lecho_redirect() //TODO:fix redirect bug.
{
	int fd;
	pid_t pid;
	char filename[MAX_LINE];

	for (int i = 1; i < cmd_cnt; i++)
	{
		if (strcmp(grd[i], ">") == 0 || strcmp(grd[i], ">>") == 0)
		{
			if (grd[i + 1] == NULL) //If there is no path name after > and >>
			{
				printf("stu1459_mysh: syntax error\n");
			}
			else
			{
				strcpy(filename, grd[i + 1]);
			}
			if (strcmp(grd[i], ">") == 0)
			{
				fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600); //Because you want to rewrite, you must use O_TRUNC
				if (fd < 0)
				{
					perror("stu1459_mysh: open");
					exit(1);
				}
				if ((pid = fork()) == 0)
				{
					dup2(fd, 1); //Redirect stdout to fd
					for (int j = 1; j < i; j++)
					{
						printf("%s ", grd[j]); //The printed content actually went to the file (because it has been redirected)
					}
					exit(0);
				}
				else if (pid > 0)
				{
					waitpid(pid, NULL, 0);
				}
				else
				{
					perror("stu1459_mysh: fork");
					exit(1);
				}
				close(fd);
			}
			else
			{															  //If it is >>, implement an append redirect
				fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0600); //In this case, you must use O_APPEND
				if (fd < 0)
				{
					perror("stu1459_mysh: open");
					exit(1);
				}
				if ((pid = fork()) == 0)
				{
					dup2(fd, 1);
					for (int j = 1; j < i; j++)
					{
						printf("%s ", grd[j]);
					}
					exit(0);
				}
				else if (pid > 0)
				{
					waitpid(pid, NULL, 0);
				}
				else
				{
					perror("stu1459_mysh: fork");
					exit(1);
				}
				close(fd);
			}
		}
	}
}
