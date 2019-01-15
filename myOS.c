/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* myOS.c is the entry point to tHE mini OS that you'll be developing throughout
* CS3305.
*
******************************************************************************/

#include "myOS.h"

/******************************************************************************
* Main function.
******************************************************************************/
int main(int argc, char** argv)
{
	if (argc > 1) {
		/**********************************************************************
		* executes the shell program
		**********************************************************************/
		if (!strcmp(argv[1], SHELL)) shell(argv[2]);

		/**********************************************************************
		* executes the process and memory memory management simulator
		**********************************************************************/
		else if (!strcmp(argv[1], SIMULATOR))
		{
			if (argc < 3) printf("\nPlease provide an input file to the "
				"simulator.\n\n");

			simulator(argv[2]);
			
		}
		else goto FAIL;
	} else goto FAIL;

	return SUCCESS;
	
	FAIL:
	printf(
		"\nUsage:\n \t./myOS COMMAND\n\nAvailable commands:\n"
		"\t1. shell\n"
		"\t2. simulator\n"
		"\n"
	);

	return FAILURE;
}