#include "stu1459_mysh.h"

int main()
{

	while (1)
	{
		/** Display terminal prompt. **/
		show_shell();

		/** Get input and transfer it to command. **/
		get_command();

		/** Execute the command based on your input. **/

		if (match(grd[0], "clear") == 1)
		{
			lclear();
		}

		else if (match(grd[0], "ls") == 1)
		{
			lls();
		}

		else if (match(grd[0], "echo") == 1)
		{
			lecho();
		}

		else if (match(grd[0], "cat") == 1)
		{
			lcat();
		}

		else if (match(grd[0], "mkdir") == 1)
		{
			lmkdir();
		}

		else if (match(grd[0], "rm") == 1)
		{
			lrm();
		}

		else if (match(grd[0], "cd") == 1)
		{
			lcd();
		}

		else if (match(grd[0], "pwd") == 1)
		{
			lpwd();
		}

		else if (match(grd[0], "wc") == 1)
		{
			lwc();
		}

		else if (match(grd[0], "about") == 1)
		{
			char *welcome = "\n\
			This is a simple simulation of Linux shell!\n\
			If you really like my project, you can star it on https://github.com/Titanlbr520/stu_mysh\n\
			And I sincerely expect your suggestions. \n\n";
			printf("%s", welcome);
		}

		else if (match(grd[0], "list") == 1)
		{
			show_command_list();
		}

		else if (match(grd[0], "man") == 1)
		{
			if (grd[1])
				show_command_doc(grd[1]);
			else
			{
				printf("\nWhat manual page do you want?\n\n");
				continue;
			}
		}

		else if (NULL == grd[0])
		{
			continue;
		}

		else if (match(grd[0], "exit") == 1 || match(grd[0], "quit") == 1)
		{
			exit(0);
		}

		else
		{
			printf("stu1459_mysh: command not found: %s\n", grd[0]);
		}
	}
	return 1;
}

void show_shell()
{
	/* The terminal prompt consists of: [username +@+hostname+current directory]+user prompt. */

	uid_t uid;
	char *ret = NULL;
	struct passwd *user = NULL;
	char hostname[100];
	char cwd[MAX_PATH_LEN];

	/* Get user id. */
	uid = getuid();

	/* Get the user's passwd structure according to uid. */
	user = getpwuid(uid);
	printf("[%s@", user->pw_name); // Print username.

	/* Get the host name */
	gethostname(hostname, 100);
	printf("%s:", hostname); // Print host name.

	/* Get the current working directory. */
	getcwd(cwd, 120);
	if (strcmp(cwd, user->pw_dir) == 0)
	{
		printf("~"); // Home directory special handling.
	}
	else
	{
		ret = strrchr(cwd, '/'); // Get the last directory of the path.
		if (ret[1] == '\0')
		{
			printf("/]"); // Root directory.
		}
		else
		{
			printf("%s]", ret + 1);
		}
	}

	/* Print user prompt. */
	if (0 == uid)
	{
		printf("# "); // Root.
	}
	else
	{
		printf("$ "); // General user.
	}

	fflush(stdout); // Refresh the terminal prompt.
}

void get_command()
{
	cmd_cnt = 0;
	char str[MAX_LINE]; // Save your original input.
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

void show_command_list()
{
	char *commondlist[] = {"\nabout",
						   "ls [FILE]...",
						   "echo",
						   "cat [FILE]...",
						   "mkdir DIRECTORY...",
						   "rm [-r/-R] [FILE]...",
						   "cd",
						   "pwd",
						   "wc [FILE]...",
						   "exit/quit",
						   "man [command]",
						   "clear",
						   "list\n"};

	for (int i = 0; i < sizeof(commondlist) / sizeof(commondlist[i]); i++)
	{
		printf("%s\n", commondlist[i]);
	}
}

// char *get_comlist()
// {
// 	char *commondlist[] = {"ls",
// 						   "echo",
// 						   "cat",
// 						   "mkdir",
// 						   "rm",
// 						   "cd",
// 						   "pwd",
// 						   "wc",
// 						   "exit/quit",
// 						   "man [command]",
// 						   "clear",
// 						   "list"};

// 	return *commondlist;
// }

void show_command_doc()
{

	/** Manual for each command **/
	char *ls_doc = "\nls [FILE]... - list directory contents\n\n";
	char *echo_doc = "\necho - display a line of text\n\n";
	char *cat_doc = "\ncat [FILE]... - concatenate files and print on the standard output\n\n";
	char *mkdir_doc = "\nmkdir DIRECTORY... - make directories\n\n";
	char *rm_doc = "\nrm [-r/-R] [FILE]... - remove files or directories\n\n";
	char *cd_doc = "\ncd - go to the given directory\n\n";
	char *pwd_doc = "\npwd - print name of current/working directory\n\n";
	char *wc_doc = "\nwc [FILE]... - print newline, word, and byte counts for each file\n\n";
	char *exit_doc = "\nexit/quit - cause normal process termination\n\n";
	char *man_doc = "\nman [command] - show the manul of command\n\n";
	char *clear_doc = "\nclear - clear the terminal screen\n\n";
	char *list_doc = "\nlist - show the command list\n\n";

	if (match(grd[1], "ls") == 1)
	{
		printf("%s", ls_doc);
	}
	else if (match(grd[1], "echo") == 1)
	{
		printf("%s", echo_doc);
	}
	else if (match(grd[1], "cat") == 1)
	{
		printf("%s", cat_doc);
	}
	else if (match(grd[1], "mkdir") == 1)
	{
		printf("%s", mkdir_doc);
	}
	else if (match(grd[1], "rm") == 1)
	{
		printf("%s", rm_doc);
	}
	else if (match(grd[1], "cd") == 1)
	{
		printf("%s", cd_doc);
	}
	else if (match(grd[1], "pwd") == 1)
	{
		printf("%s", pwd_doc);
	}
	else if (match(grd[1], "wc") == 1)
	{
		printf("%s", wc_doc);
	}
	else if (match(grd[1], "exit") == 1 || match(grd[1], "quit") == 1)
	{
		printf("%s", exit_doc);
	}
	else if (match(grd[1], "man") == 1)
	{
		printf("%s", man_doc);
	}
	else if (match(grd[1], "clear") == 1)
	{
		printf("%s", clear_doc);
	}
	else if (match(grd[1], "list") == 1)
	{
		printf("%s", list_doc);
	}
	else
	{
		printf("No manual entry for %s\n", grd[1]);
	}

	// char *commanddoc[] = {"ls [FILE]... - list directory contents",
	// 					  "echo - display a line of text",
	// 					  "cat [FILE]... - concatenate files and print on the standard output",
	// 					  "mkdir DIRECTORY... - make directories",
	// 					  "rm [-r/-R] [FILE]... - remove files or directories",
	// 					  "cd - go to the given directory",
	// 					  "pwd - print name of current/working directory",
	// 					  "wc [FILE]... - print newline, word, and byte counts for each file",
	// 					  "exit/quit - cause normal process termination",
	// 					  "man - show the manul of command",
	// 					  "clear - clear the terminal screen",
	// 					  "list - show the command list"};

	// char *commandlist[] = get_comlist();

	// for (int i = 0; i < strlen(*commanddoc); i++)
	// {
	// 	if (match(command, commandlist[i]) == 1)
	// 	{
	// 		printf("\n%s\n\n", commanddoc[i]);
	// 	}
	// }
}

void lclear()
{
	printf("\033[2J"); //clear
	printf("\033[H");  //move the mouse to a proper positoin
}
