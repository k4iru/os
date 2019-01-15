/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* job.h cotains the defenitions for the job typedef
*
******************************************************************************/

#ifndef JOB_H
#define JOB_H

#include <stdlib.h>
#include <string.h>

typedef struct
{
	int number, required_memory, required_time;
} job_t;

job_t* init_job(int, int, int);

#endif