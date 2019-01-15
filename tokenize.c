/******************************************************************************
* 
* Name: 	Kyle Cheung
* Email: 	kcheu4@uwo.ca
*
* tokenize.c tokenizes the input lines. sperates commands by '<', '>' and '|'
*
******************************************************************************/

#include "tokenize.h"

void process_io_redirection_commands(short cmd, char *command_line,
	d_linked_list_t *commands, int start, int other_start, int len)
{
	/**************************************************************************
	* find length of 
	**************************************************************************/
	if (other_start != -1 && other_start > start)
		len = other_start - start - 1;
	else len -= start;

	char *io_argument = trim(command_line + start, len);

	len = CMD_LENGTH + strlen(io_argument) + 1;

	/**************************************************************************
	* add cat/out/tee command to commands 
	**************************************************************************/
	char* value = malloc(len + 1);

	if (cmd == CAT_CMD) memcpy(value, CAT, CMD_LENGTH);
	else if (cmd == OUT_CMD) memcpy(value, OUT, CMD_LENGTH);
	else if (cmd == TEE_CMD) memcpy(value, TEE, CMD_LENGTH);

	memcpy(value + CMD_LENGTH, " ", 1);
	memcpy(value + CMD_LENGTH + 1, io_argument, len - CMD_LENGTH - 1);
	value[len] = '\0';

	enqueue(commands, (void*)value);

	free(io_argument);
}

void extract_command(char *command_line, d_linked_list_t *commands, int len)
{

	int input_start = -1,
		input_len = -1,
		output_start = -1,
		output_len = -1,
		command_len = len;

	/**************************************************************************
	* find any IO redirections and only keep the last one; find command length
	* if there exsits an IO redirection
	**************************************************************************/
	for(int i = 0; i < len; ++i)
	{
		if (command_line[i] == INPUT_REDIRECTION ||
			command_line[i] == OUTPUT_REDIRECTION)
		{
			if(command_line[i] == INPUT_REDIRECTION) input_start = i + 1;
			if(command_line[i] == OUTPUT_REDIRECTION) output_start = i + 1;
			if(command_len == len) command_len = i - 1;
		}
	}

	/**************************************************************************
	* find length of input redirection and add command to commands 
	**************************************************************************/
	if (input_start != -1)
	{
		process_io_redirection_commands(CAT_CMD, command_line, commands,
			input_start, output_start, len);
	}


	/**************************************************************************
	* add command to commands
	**************************************************************************/
	enqueue(commands, (void*)trim(command_line, command_len));

	/**************************************************************************
	* find length of input redirection and add command to commands 
	**************************************************************************/
	if (output_start != -1)
	{
		process_io_redirection_commands(OUT_CMD, command_line, commands,
			output_start, input_start, len);
	}
}

char*** tokenize(char* command_line)
{
	int i = -1, j = 0;

	d_linked_list_t *commands = init_d_linked_list();

	/**************************************************************************
	* splits commands on pipes
	**************************************************************************/
	while (command_line[++i] != '\0')
	{
		if (command_line[i] == PIPE)
		{
			extract_command(command_line + j, commands, i - j);
			j = i + 1;
		}
	}
	/**************************************************************************
	* exctracts the last command
	**************************************************************************/
	extract_command(command_line + j, commands, i - j);

	return transform_d_linked_list_to_3d_char(commands);
}
