#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#include "cmdline.h"

#define BUFLEN 4096

#define YESNO(i) ((i) ? "Y" : "N")

#define INPUT_REDIRECT 0
#define OUTPUT_REDIRECT 1

static int bg_status;
static pid_t bg_pid = -1;

//Handle input and output redirection. Return the new file descriptor if succeeded, -1 if not
int redirect(const char *file, int type)
{
	//NULL file
	if(!file)
	{
		fprintf(stderr, "Error : Cannot redirect to a NULL file.\n");
		return -1 ;
	}

	printf("Redirecting %s to file '%s'.\n", (type == INPUT_REDIRECT) ? "input" : "output", file);

	//Wrong type
	if(type != INPUT_REDIRECT && type != OUTPUT_REDIRECT)
	{
		fprintf(stderr, "Error : wrong redirection type in source code.\n");
		return -1 ;
	}

	//opening file
	int flags = (type == INPUT_REDIRECT) ? O_RDONLY : (O_WRONLY | O_CREAT);
	int fd = open(file, flags);
	if(fd < 0)
	{
		fprintf(stderr, "Unable to open file '%s'\n",file);
		return -1;
	}

	//Redirecting
	int dup_fd = (type == INPUT_REDIRECT) ? STDIN_FILENO : STDOUT_FILENO;
	if(dup2(fd, dup_fd) < 0)
	{
		fprintf(stderr, "Unable to redirect %s\n", (type == INPUT_REDIRECT) ? "input" : "output");
		return -1;
	}

	close(fd);

	return 0;
}

//Handle internal commands like cd or exit. Return 1 if an internal command other than exit has been executed, -1 if more than 1 commands, 0 if no internal commands.
int internal_cmds(struct line li)
{
	if(li.ncmds > 1)
	{
		return -1;
	}

	//exit command
	if(strcmp(li.cmds[0].args[0],"exit") == 0)
	{
		printf("exiting...\n\n");
		line_reset(&li);
		exit(EXIT_SUCCESS);
	}

	//cd command
	if(strcmp(li.cmds[0].args[0],"cd") == 0)
	{
		chdir(li.cmds[0].args[1]);
		return 1;
	}

	return 0;
}

//Handler used for background process
void SIGCHLD_handler(int sig)
{
	if(bg_pid != -1)
	{
		waitpid(bg_pid, &bg_status, 0);
		if(WIFEXITED(bg_status)){
			printf("Background : son %d exited with code %d.\n", bg_pid, WEXITSTATUS(bg_status));
		}
		bg_pid = -1;
	}
}

//Print line stats
void line_stats_print(const struct line li)
{
	printf("Command line:\n");
	printf("\tNumber of commands: %zu\n", li.ncmds);

	size_t i, j;
	for (i = 0; i < li.ncmds; ++i)
	{
		printf("\t\tCommand #%zu:\n", i);
		printf("\t\t\tNumber of args: %zu\n", li.cmds[i].nargs);
		printf("\t\t\tArgs:");
		for (j = 0; j < li.cmds[i].nargs; ++j)
		{
			printf(" \"%s\"", li.cmds[i].args[j]);
		}
		printf("\n");
	}

	printf("\tRedirection of input: %s\n", YESNO(li.redirect_input));
	if (li.redirect_input)
	{
		printf("\t\tFilename: '%s'\n", li.file_input);
	}

	printf("\tRedirection of output: %s\n", YESNO(li.redirect_output));
	if (li.redirect_output)
	{
		printf("\t\tFilename: '%s'\n", li.file_output);
	}

	printf("\tBackground: %s\n", YESNO(li.background));
}

//Handle the execution of a line without pipe
void line_execute(struct line li, struct sigaction action, struct sigaction oldact)
{
	internal_cmds(li);

	//Fork
	int child_status;
	pid_t child_pid = fork();

	//Son
	if(child_pid==0)
	{
		/*------------------------------------------------
							HANDLERS
		------------------------------------------------*/
		//Foreground process	
		if(li.background == 0)
		{
			sigaction(SIGINT, &oldact, NULL);//reseting default handler of SIGINT in child process
		}
		//Background process
		else{
			action.sa_handler = SIGCHLD_handler;
			sigaction(SIGCHLD, &action, NULL);
		}

		/*------------------------------------------------
							REDIRECTION
		------------------------------------------------*/
		//input redirection
		if(li.redirect_input)
		{
			if(redirect(li.file_input, INPUT_REDIRECT) < 0)
			{
				exit(EXIT_FAILURE);
			}
		}

		//output redirection
		if(li.redirect_output)
		{
			if(redirect(li.file_output, OUTPUT_REDIRECT) < 0)
			{
				exit(EXIT_FAILURE);
			}
		}

		/*------------------------------------------------
							EXECUTION
		------------------------------------------------*/
		execvp(li.cmds[0].args[0],li.cmds[0].args);
		fprintf(stderr,"Unknown command '%s'\n",li.cmds[0].args[0]);
		exit(EXIT_FAILURE);
	}
	//Father
	else
	{
		//Foreground process
		if(li.background == 0)
		{
			waitpid(child_pid,&child_status,0);
			if(WIFEXITED(child_status)){
				fprintf(stdout,"Son %d exited with code %d.\n", child_pid, WEXITSTATUS(child_status));
			}
		}
		//Background process
		else
		{
			bg_pid = child_pid;
			fprintf(stdout, "Background process created with pid %d.\n",bg_pid);
		}
	}
}

//Handle a command line with pipes
void pipe_exec(struct line li, struct sigaction action, struct sigaction oldact)
{
	if(internal_cmds(li) != -1)
	{
		return ;
	}

	int pipes[li.ncmds - 1][2];
	for(size_t i=0; i<li.ncmds; i++)
	{
		if(i != li.ncmds - 1)
		{
			pipe(pipes[i]);
		}

		if(fork() == 0)
		{
			if(i == 0)//first comand
			{
				//Output of process to input of first pipe
				dup2(pipes[0][1],STDOUT_FILENO);
			}
			else if (i  == li.ncmds - 1)//last command
			{
				//Output of last pipe to input of process
				dup2(pipes[i-1][0],STDIN_FILENO);
			}
			else//others commands
			{
				//Output of previous pipe to input of process
				dup2(pipes[i-1][0],STDIN_FILENO);
				//Output of process to input of next pipe
				dup2(pipes[i][1],STDOUT_FILENO);
			}
			
			//closing pipe in child
			close(pipes[i][1]);
			close(pipes[i][0]);

			/*------------------------------------------------
								EXECUTION
			------------------------------------------------*/
			execvp(li.cmds[i].args[0],li.cmds[i].args);
			fprintf(stderr,"Unknown command '%s'\n",li.cmds[i].args[0]);
			exit(EXIT_FAILURE);
		}
	}
	
	for(size_t i=0; i<li.ncmds-1; i++)//closing pipes in father
	{
		close(pipes[i][1]);
		close(pipes[i][0]);
	}
	
	for(size_t i=0; i<li.ncmds; i++)//waiting for all commands
	{
		wait(NULL);
	}
}

/*
	arg10 | arg 20 | arg 30 < toto > tata
	arg10 auras toto comme entrée et arg30 tata comme sortie
	les redirections sont touours en fin de commande
*/

int main()
{
	struct sigaction action;
	struct sigaction oldact;//save the default action when SIGINT is received


	sigemptyset(&action.sa_mask);
	action.sa_handler = SIG_IGN;//ignoring SIGINT in main process
	action.sa_flags = 0;
	sigaction(SIGINT, &action, &oldact);

	struct line li;
	char buf[BUFLEN];//Buffer
	char wd[BUFLEN];//Workdir
	line_init(&li);

	for (;;) {
		printf("fish: %s> ",getcwd(wd,BUFLEN));
		fgets(buf, BUFLEN, stdin);

		int err = line_parse(&li, buf, strlen(buf));
		if (err)
		{
			line_reset(&li);
			continue ;
		}

		//Void command line
		if(li.ncmds == 0)
		{
			continue ;
		}

		//Print command line informations
		line_stats_print(li);

		//A single command
		if(li.ncmds == 1)
		{
			line_execute(li, action, oldact);
		}
		else//command line with pipes
		{
			pipe_exec(li, action, oldact);
		}

		line_reset(&li);
	}
	line_reset(&li);
	return EXIT_SUCCESS;
}

/*
	Can only wait the last background process
*/