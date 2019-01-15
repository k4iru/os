/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* scheduler.h
*
******************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "job.h"
#include "d_linked_list.h"
#include "helper.h"

job_t *get_next_job(int, d_linked_list_t*);

#endif
