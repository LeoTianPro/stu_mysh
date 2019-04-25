#include "stu1459_mysh.h"

int main()
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

	while (1)
	{
		/** Display terminal prompt. **/
		showShell();

		/** Get input and transfer it to command. **/
		getCommand();

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
			printf("This is a simple simulation of bash in Linux!");
		}

		else if (match(grd[0], "list") == 1)
		{
			printf("command list:ls\necho\ncat\nmkdir\nrm\ncd\npwd\nwc\nman\nlist");
		}

		else if (match(grd[0], "man") == 1 && grd[1])
		{
			if (match(grd[1], "ls") == 1)
				printf("%s", ls_doc);
			else if (match(grd[1], "echo") == 1)
				printf("%s", echo_doc);
			else if (match(grd[1], "cat") == 1)
				printf("%s", cat_doc);
			else if (match(grd[1], "mkdir") == 1)
				printf("%s", mkdir_doc);
			else if (match(grd[1], "rm") == 1)
				printf("%s", rm_doc);
			else if (match(grd[1], "cd") == 1)
				printf("%s", cd_doc);
			else if (match(grd[1], "pwd") == 1)
				printf("%s", pwd_doc);
			else if (match(grd[1], "wc") == 1)
				printf("%s", wc_doc);
			else if (match(grd[1], "exit") == 1 || match(grd[1], "quit") == 1)
				printf("%s", exit_doc);
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

void showShell()
{
	/* The terminal prompt consists of: [username +@+hostname+current directory]+user prompt. */

	uid_t uid;
	char *ret;
	struct passwd *user;
	char hostname[100];
	char cwd[120];

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

void getCommand()
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

void lclear()
{
	printf("\033[2J"); //clear
	printf("\033[H");  //move the mouse to a proper positoin
}
