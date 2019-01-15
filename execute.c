/******************************************************************************
* 
* Name: 	Kyle Cheung
* Email: 	kcheu4@uwo.ca
*
* execute.c will handle the flow of information between processes as well as it
* exectes these processes.
*
******************************************************************************/

#include "execute.h"

/******************************************************************************
* process the given commands
******************************************************************************/
short execute(int i, char ***argv, int prev_pid, int prev_output)
{	
	int status, fd[2];
	pid_t pid;

	/**************************************************************************
	* terminate program
	**************************************************************************/
	if (!strcmp(argv[i][0], EXIT)) return TERMINATE;

	/**************************************************************************
	* output the commands execution result
	**************************************************************************/
	if (argv[i + 1] != NULL && !strcmp(argv[i + 1][0], OUT))
	{

		FILE *fp = fopen(argv[i + 1][1], WRITE);

		if (fp == NULL)
		{
			printf("Unable to open %s\n", argv[i + 1][1]);
			exit(FAILURE);
		}

		fd[1] = fileno(fp);
	}

	/**************************************************************************
	* Creates a new pipe if the program needs it. 
	**************************************************************************/
	if (argv[i + 1] != NULL && strcmp(argv[i + 1][0], OUT) && pipe(fd) < 0) 
	{
		printf("Error: failed to create a pipe.\n");
		exit(FAILURE);
	}

	/**************************************************************************
	* Forks the process
	**************************************************************************/
	switch(pid = fork())
	{

		/**********************************************************************
		* Hnadles fork failure
		**********************************************************************/
		case -1:
		{
			printf("Error: failed to fork.\n");
			exit(FAILURE);
		}

		/**********************************************************************
		* Hnadles the child process
		**********************************************************************/
		case 0:
		{
			/******************************************************************
			* If the previous child flag is not -1, then set the stdin to the 
			* output of that child
			******************************************************************/
			if (prev_pid != -1 && dup2(prev_output, STDIN_FILENO) < 0)
			{
				printf("Error: failed to dup.\n");
				exit(FAILURE);
			}
		
			/******************************************************************
			* If this is not the last sub-command, then dup the stdout to the
			* pipe.
			******************************************************************/
			if(argv[i + 1] != NULL)
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) < 0)
				{
					printf("Error: failed to dup.\n");
					exit(FAILURE);
				}
			}

			/******************************************************************
			* executes the command. if command returns to the function then an
			* error occured. Otherwise, it takes over the process.
			******************************************************************/
			execvp(argv[i][0], argv[i]);
			
			printf("-shell: %s: command not found\n", argv[i][0]);
			exit(FAILURE);	
		}

		/**********************************************************************
		* Handles the parent process
		**********************************************************************/
		default:
		{
			/******************************************************************
			* Waits on the child to finish executing
			******************************************************************/
			wait(&status);
			if (argv[i + 1] == NULL || !strcmp(argv[i + 1][0], OUT))
				return status;

			/******************************************************************
			* Close the output pipe and execute the method recursively with the 
			* next sub-command
			******************************************************************/
			close(fd[1]);
			return execute(i + 1, argv, pid, fd[0]);
		}
	}
	return SUCCESS;
}
