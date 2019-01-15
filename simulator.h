/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* simulator.h
*
******************************************************************************/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>

#include "simulate.h"
#include "job.h"
#include "d_linked_list.h"
#include "helper.h"

#define SYSTEM_SPECS "system.in"

void simulator(char*);
d_linked_list_t* build_jobs_list(char*);

#endif