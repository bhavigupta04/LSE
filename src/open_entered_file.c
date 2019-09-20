/*********************************************************************************
*	FileName : open_entered_file.c
*
*	Description : This file contains the function to display the content of user
*			entered file.
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
*	FUNCTION NAME : open_user_entered_file()
*
*	DESCRIPTION : This function let the user choose a file from the list and
*			display the content.
*
*	ARGUMENTS : No arguments.
*
*	RETURNS : SUCCESS
*
******************************************************************************/


int open_user_entered_file()
{
	FILE *fp = NULL;
	
	char buffer[MAX_SIZE] = {'\0'};		/* buffer to store data from file */
	char file_name[MAX_SIZE] = {'\0'};		/* variable for file name */ 
	char cmd_string[MAX_SIZE] = {'\0'};	/* buffer to store command */

	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: open_user_entered_file()");

	printf("\nPlease enter the file name to open: ");
	scanf("%s",file_name);
	
	/* opening the file containing the path of the listed files */
	fp = fopen("/home/saasbook/GIT/LSE/data/output.txt", "r");
	if(fp == NULL)
	{
		printf("FILE NOT OPENED\n");
		return FAILURE;
	}
	/* 
	* Reading the content of the file into the buffer.
	* File consists path of all files containing that string/pattern. 
	*/
	while(fscanf(fp, "%[^\n]\n", buffer) != EOF)
	{
		/*
		* searching file name in the buffer.
		*/
		if(strstr(buffer, file_name) != NULL)
		{
			printf("\nFILE PATH : %s\n", buffer);
			printf("\n##**************** FILE CONTENT ****************##\n\n");

			/* copying 'cat' command into buffer */
			strcpy(cmd_string, "cat ");	

			/* concatenating buffer into the command */
			strcat(cmd_string, buffer);
		
			/* system call to display the content */
			system(cmd_string);

			printf("\n##**************** FILE END ****************##\n");
		}
	}
	fclose(fp);

	/*
	* Function call for log report.
	*/
	logging_report("EXITING: open_user_entered_file()");

	return SUCCESS;	
}

