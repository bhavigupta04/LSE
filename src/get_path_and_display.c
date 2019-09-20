/*********************************************************************************
*	FileName : get_path_and_display.c
*
*	Description : This file contains the functions to get absolute path and 
*			display it's content.
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
*	FUNCTION NAME : get_absolute_path()
*
*	DESCRIPTION : This is for taking absolute path from the user.
*
*	ARGUMENTS : file_path - searching directory.
*
*	RETURNS : SUCCESS
*
******************************************************************************/

void get_absolute_path(char *file_path)
{
	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: get_absolute_path()");
	
	printf("\n\tEnter the absolute path of the file : ");
       scanf("%s", file_path);
	
	/*
	* Function call for log report.
	*/
	logging_report("EXITING: get_absolute_path()");
}

/******************************************************************************
*
*	FUNCTION NAME : display_content()
*
*	DESCRIPTION : This function displays the content of the file.
*
*	ARGUMENTS : No arguments.
*
*	RETURNS : SUCCESS
*
******************************************************************************/

int display_content()
{
	char file_path[MAX_SIZE] = {'\0'};		/* variable for storing path of searching directory */
	char cmd_string[MAX_SIZE] = {'\0'};	/* variable for building a command */

	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: display_content()");

	/*
	* Function call for taking absolute path from user.
	*/
	get_absolute_path(file_path);

	/* copying 'cat' command into buffer */
	strcpy(cmd_string, "cat ");

	/* concatenating file path into buffer */
	strcat(cmd_string, file_path);

	printf("\n******************** FILE DATA BEGIN ***************************\n\n");

	system(cmd_string);	/* system call to display the content */

	printf("\n\n*********************** FILE DATA END *************************************\n");

	/*
	* Function call for log report.
	*/
	logging_report("EXITING: display_content()");
	
	return SUCCESS;
}
