/******************************************************************************
*
*  	FILE NAME    : search_util.h
*
*	DESCRIPTION  : This file contains Header Files, Macros and function 
*			 prototypes.
*
*	DATE		NAME			REFERENCE		  REASON
*  	30/04/18	GR_TH5_C_5		Local Search Engine	  Nalanda Project
*
*  	Copyright 2018, Aricent Tech. (Holdings) Ltd.
*
******************************************************************************/

#ifndef __SEARCH_UTIL_H__
#define __SEARCH_UTIL_H__

/******************************************************************************
*
*				* COMMON STATNDARD HEADER FILES *
*
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <ctype.h>

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/******************************************************************************
*
*				* MACROS DEFINITION *
*
******************************************************************************/

#define SUCCESS 1
#define FAILURE 0
//#define NORMAL 1

/* Size for user string/pattern and path*/
#define MAX_SIZE 1024		
#define PATH_SIZE 100

/******************************************************************************
*
*				* FUNCTIONS PROTOTYPE *
*
******************************************************************************/

/* Function for taking absolute path from the user */
void get_absolute_path(char *file_path);

/* function to display the content of the file */
int display_content();

/* Function for choosing a file from the list and display the content */
int open_user_entered_file();

/* function to search the string in the file system and displays the 
*  path of the files in which it is found.
*/
int search_pattern_in_file_system(char *dir, char *user_pattern, FILE *fp, int *count);

/* function for matching the user string/pattern in the file */
int match_pattern(char *file_name, char *user_pattern);

/* function to read the temporary file and store it in buffer */
void read_temp_file(char *path_buffer);

/* function to remove the leading spaces from string/pattern */
void trim_leading_space(char * str);

/* function to generate logging report */
void logging_report(char *buf);

#endif

