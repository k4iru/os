/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* job.c cotains the helper functions for the job typedef
*
******************************************************************************/

#include "job.h"

job_t* init_job(int number, int required_memory, int required_time)
{
	job_t *j = (job_t*)malloc(sizeof(job_t));
	j->number = number;
	j->required_memory = required_memory;
	j->required_time = required_time;

	return j;
}
