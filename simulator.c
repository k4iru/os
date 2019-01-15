/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* simulator.c 
*
******************************************************************************/

#include "simulator.h"

/******************************************************************************
* 
******************************************************************************/
void simulator(char *filename)
{
	FILE *fp = fopen(SYSTEM_SPECS, READ);
	int memory, mode, quantum;

	/**************************************************************************
	* check if the system file is in the directory
	**************************************************************************/
	if (fp == NULL)
	{
		printf("Unable to open %s file\n", SYSTEM_SPECS);
		exit(FAILURE);
	}
	/**************************************************************************
	* set the main memory value to the value read from the system file
	**************************************************************************/
	fscanf(fp, "%d %d %d", &memory, &mode, &quantum);
	fclose(fp);

	d_linked_list_t *jobs = build_jobs_list(filename);
	job_t *p;

	simulate(memory, mode, quantum, jobs);
}

/******************************************************************************
* Scans input file and builds a stack of jobs
******************************************************************************/
d_linked_list_t* build_jobs_list(char *filename) {

	FILE *fp = fopen(filename, READ);

	/**************************************************************************
	* check if the input file exists
	**************************************************************************/
	if (fp == NULL)
	{
		printf("Unable to open %s file\n", filename);
		exit(FAILURE);
	}

	int number, memory, time, len;
	d_linked_list_t *l = init_d_linked_list();

	/**************************************************************************
	* load all simulation jobs into the jobs stack
	**************************************************************************/
	while(fscanf(fp, "%d %d %d", &number, &memory, &time) == 3)
		enqueue(l, (void*)init_job(number, memory, time));

	fclose(fp);

	return l;
}
