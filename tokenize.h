/******************************************************************************
* 
* Name: 	Kyle Cheung
* Email: 	kcheu4@uwo.ca
*
* tokenize.h
*
******************************************************************************/


#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <stdlib.h>
#include <string.h>

#include "helper.h"
#include "d_linked_list.h"

void process_io_redirection_commands(short, char *, d_linked_list_t*, int, int,
	int);
void extract_command(char*, d_linked_list_t*, int);
char*** tokenize(char*);

#define PIPE '|'
#define INPUT_REDIRECTION '<'
#define OUTPUT_REDIRECTION '>'

#define CMD_LENGTH 3

#define CAT_CMD 1
#define TEE_CMD 2
#define OUT_CMD 3

#endif
