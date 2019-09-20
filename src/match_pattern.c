/*********************************************************************************
*	FileName : match_pattern.c
*
*	Description : This file contains the functions to search for the 
*			string/pattern in the files.
*
*	Date:		Name:		Reference:		Reason:
*	30/04/18	GR_TH5_C_5	Local Search Engine	Nalanda Project
*
*	Copyright @2018, Aricent Tech. Holdings Ltd.
*
**********************************************************************************/

/******************************************************************************
*
*				USER DEFINED HEADER 
*
******************************************************************************/

#include <search_util.h>

/******************************************************************************
*
*	FUNCTION NAME : match_pattern()
*
*	DESCRIPTION : This function is used for matching the user string/pattern
*			in the file.
*
*	ARGUMENTS : file_name - file to search in.
*		     user_pattern - string/pattern to search for.
*
*	RETURNS : return SUCCESS on match otherwise returns FAILURE.
*
******************************************************************************/

int match_pattern(char *file_name, 
		    char *user_pattern)
{
	FILE *fp = NULL;
    	char file_data[MAX_SIZE] = {'\0'};	/* buffer to store the file data */ 

	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: match_pattern()");

	/* Opening the file in read mode */
    	if((fp = fopen(file_name, "r")) != NULL)
    	{
		/* Reading data into buffer from file */
    		while(fgets(file_data, sizeof(file_data), fp) != NULL)
    		{	
			/* Matching the pattern */
        		if(strstr(file_data, user_pattern) != NULL)
		    	{   
                		memset(file_data, '\0', sizeof(file_data));	/* flushing the buffer */
			    	fclose(fp);						/* file closing */
				
				//logging_report(NORMAL, "EXITING: match_pattern()");
			    	return SUCCESS;					/* returning SUCCESS on match */
            		}
    		}
    	}   
	else
	{
		printf("%s File not opened\n", file_name);
	}
	fclose(fp);
	
	/*
	* Function call for log report.
	*/
	logging_report("EXITING: match_pattern()");
	
	return FAILURE;
}

/******************************************************************************
*
*	FUNCTION NAME : read_temp_file()
*
*	DESCRIPTION : This function read the temporary file and store it in
			buffer.
*
*	ARGUMENTS : path_buffer - empty buffer
*
*	RETURNS : NULL
*
******************************************************************************/

void read_temp_file(char *path_buffer)
{
	FILE *fp = NULL;

	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: read_temp_file()");

   	/* Opening the temp file in read mode */
	fp = fopen("/home/saasbook/GIT/LSE/data/temp_file.txt", "r");
	if(fp == NULL)
	{
		printf("\nFile not opened\n");
    	}
	
	/* Reading data into path_buffer from the file */	
	fscanf(fp, "%s", path_buffer);
    	
	fclose(fp);	/* closing the file */

	/*
	* Function call for log report.
	*/
	logging_report("EXITING: read_temp_file()");

}
