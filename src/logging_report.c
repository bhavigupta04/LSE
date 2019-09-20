/******************************************************************************
*
*  FILE NAME   : logging_report.c
*
*  DESCRIPTION : it include functions to genrate logging report.
*
*  DATE	NAME		REFERENCE				REASON
*  4/05/18	GR_TH5_C_5	Local Search Engine 	  	Nalanda Project
*
*  Copyright 2018, Aricent Tech. (Holdings) Ltd.
*
******************************************************************************/

/******************************************************************************
*
*				USER DEFINED HEADER 
*
******************************************************************************/

#include <search_util.h>			

/******************************************************************************
*
*	FUNCTION NAME	: logging_report
*
*	DESCRIPTION	: This function writes message into log_report file.
*
*	ARGUMENTS	: buf - message to be written.	
*
*	RETURNS 	: VOID
*
******************************************************************************/

void logging_report(char *buf)
{	
		/* Initializations */
		FILE* fp1 = NULL;
		
		/* Opening file to store the log message in it */
		fp1 = fopen("/home/saasbook/GIT/LSE/logging_dir/log_report.txt", "a");
	
		fprintf(fp1,"%s\n",buf);
	
		/* Closing the file */
		fclose(fp1);

}

