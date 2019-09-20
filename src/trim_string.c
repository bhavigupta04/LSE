/*********************************************************************************
*
*  FILE NAME   : trim_string.c
*
*  DESCRIPTION : This file contains a function to remove leading spaces.
*
*  DATE	NAME		REFERENCE				REASON
*  4/05/18	GR_TH5_C_5	Local Search Engine 	  	Nalanda Project
*
*  Copyright 2018, Aricent Tech. (Holdings) Ltd.
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
*	FUNCTION NAME : trim_leading_space
*
*	DESCRIPTION : This function remove all leading spaces present in the string.
*
*	ARGUMENTS : str - string/pattern .
*
*	RETURNS : VOID.
*
******************************************************************************/


void trim_leading_space(char * str)
{
    	int index;
	int i = 0;;

    	index = 0;
	
	/*
	* Function call for log report.
	*/	
	logging_report("ENTERING: trim_leading_space()");
    	
	/* Find last index of whitespace character */
    	while((str[index] == ' ') || (str[index] == '\t') || (str[index] == '\n'))
    	{
       	index++;
    	}

    	if(index != 0)
    	{
       	 /* Shit all trailing characters to its left */
       	 i = 0;
       	 while(str[i + index] != '\0')
        	{
            		str[i] = str[i + index];
            		i++;
        	}
        	str[i] = '\0'; // Make sure that string is NULL terminated
    	}

	/*
	* Function call for log report.
	*/
	logging_report("EXITING: trim_leading_space()");

}