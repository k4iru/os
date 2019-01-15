/******************************************************************************
* 
* Name: 	Kyle Cheung
* Email: 	kcheu4@uwo.ca
*
* shell.c processes the users input, passes it to a tokenizer, and then passes
* the tokens obtained to the process_commands function which will process and
* execute the commands.
*
******************************************************************************/

#include "shell.h"

/******************************************************************************
* Processes the input and determine whether it is a user interface operation 
* or a set of commands that will need to be executed.
******************************************************************************/
void shell(char* filename)
{

	/**************************************************************************
	* short			special_char 	determines whether the character to be 
	*								processed is special or not.
	* int 			len 			keeps track of the current line length
	* char 			command_line 	holds current command line
	**************************************************************************/
	short status = 0, special_char = FALSE;
	char ch, *command_line = (char*)malloc(MAX_STR_LEN);
	int len = 0;
	FILE *fp = NULL;

	if (filename != NULL)
	{
		fp = fopen(filename, READ);

		if (fp == NULL) printf("Unable to open %s\n", filename);

	}

	/**************************************************************************
	* Loops until the user exits the program.
	**************************************************************************/
	print_user();
	while(status != TERMINATE)
	{

		ch = getch(fp);
			
		if (special_char)
		{
			special_char = FALSE;
			ch = switch_keypad(ch);
		}

		/**********************************************************************
		* switchs arround possible cases depending on the read character
		**********************************************************************/
		switch(ch)
		{
			/******************************************************************
			* handles the ascii translation of arrow characters
			******************************************************************/
			case '\033':
				getch(NULL);
				special_char = TRUE;
				continue;

			/******************************************************************
			* ignore arrow characters and tab
			******************************************************************/
			case KEYLEFT:
			case KEYRIGHT:
			case KEYUP:
			case KEYDOWN:
			case TAB:
				break;

			/******************************************************************
			* handles backspacing
			******************************************************************/
			case DELETE:
				if (len > 0) delete(--len, command_line);
				break;

			/******************************************************************
			* if the maximum command_line length is not exceeded the program
			* will print the character. if the character is not a new line then
			* continue. Else, terminate command_line, pass it to the
			* execute_commands function, allocate a new command_line, and reset
			* the command_line length. 
			******************************************************************/
			default:
			{
				if (len < MAX_STR_LEN)
				{

					if (ch != '\n')
					{
						printf("%c", ch);
						command_line[len++] = ch;
					}

					else if (ch == '\n' && len > 0)
					{
						printf("%c", ch);
						command_line[len] = '\0';
						status = execute_commands(command_line);
						
						free(command_line);

						command_line = (char*)malloc(MAX_STR_LEN);
						len = 0;

						if (status != TERMINATE) print_user();
					}
				}
				break;
			}
		}
	}

	fclose(fp);
}

/******************************************************************************
* execute_commands acts like a bridge between the tokenized commands and the
* commands interpreter
******************************************************************************/
short execute_commands(char* command_line)
{
	short status;
	char ***argv;

	/*************************************************************************
	* sends the commands to be processed and stores the result into commands
	*************************************************************************/
	if ((argv = tokenize(command_line)) == NULL)
	{
		printf("Syntax error\n");
		return FAILURE;
	}
	
	/**************************************************************************
	* sends the commands to the commands interpreter. If the commands is 
	* exit, then terminate, else, process the line
	**************************************************************************/
	status = execute(0, argv, -1, -1);

	/**************************************************************************
	* clean up the argv array.
	**************************************************************************/
	for(int i = 0; argv[i] != NULL; ++i)
	{
		for(int j = 0; argv[i][j] != NULL; ++j) free(argv[i][j]);
		free(argv[i]);
	}
	free(argv);
	
	return status;
}
