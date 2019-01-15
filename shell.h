/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* shell.h
*
******************************************************************************/

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"
#include "tokenize.h"
#include "execute.h"

void shell(char*);
short execute_commands(char*);

#endif