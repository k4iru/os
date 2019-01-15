/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* execute.h 
*
******************************************************************************/

#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "helper.h"

short execute(int, char***, int, int);

#endif