/*******************************************************************************
*	FileName : main_interface.c
*
*	Description : This file contains the main function for diplaying the 
*			user interface and the various function calls.
*
*	Date:		Name:		Reference:		Reason:
*	30/04/18	GR_TH5_C_5	Local Search Engine	Nalanda Project
*
*	Copyright @2018, Aricent Tech. Holdings Ltd.
*
*******************************************************************************/

/******************************************************************************
*
*				USER DEFINED HEADER 
*
******************************************************************************/

#include <search_util.h>
 
/******************************************************************************
*
*	FUNCTION NAME : main()
*
*	DESCRIPTION : This is main function for calling other functions.
*
*	ARGUMENTS : No arguments
*
*	RETURNS : Returns SUCCESS as exit status.
*
******************************************************************************/

int main()
{
	/* Variables Initializations */ 
	FILE *fp = NULL;	

	int choice = 0;	/* variable for switch case */
	int count = 0;	/* for number of matches found */
	int result = 0;		/* for checking status */ 	
    	char path[PATH_SIZE] = "/home/saasbook/GIT/LSE/file_system/";	/* path of searching directory */
    	char user_string[MAX_SIZE] = {'\0'};	/* user input string/pattern */
	
	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: main");
	
	while(SUCCESS)
	{
		printf("\n*******************************************************************\n\n");
		printf("\n\t\tWELCOME TO LOCAL SEARCH ENGINE\n");
		printf("\n\n*******************************************************************\n");
			
		printf("\nPRESS 1: TO SEARCH A WORD/STRING\t\n");
		printf("\nPRESS 2: TO SEARCH A FILE\t\n");
		printf("\nPRESS 3: TO DISPLAY LIST OF ALL FILES\n\t");
		printf("\nPRESS 4: TO EXIT\n");
		
		/* Taking user's choice */
		printf("\nPlease enter your choice : ");
		scanf("%d", &choice);
		 
		count = 0;	/* making count 0 for each iteration */

		/**** Processing Starts ****/
		switch(choice)
		{
			/*
			* This case is for taking an input string/pattern and search it in the file system
			* and displays the list of files containing the particular string/pattern.
			*/
			case 1:
				memset(user_string, '\0', sizeof(user_string));
				printf("\nPlease enter the string/pattern to search: ");
				getchar();
				scanf("%[^\n]",user_string);
				trim_leading_space(user_string);
				printf("len:%d\n", (int)strlen(user_string));
				if(strlen(user_string) == 0)
				{
					printf("Please enter the string\n");
					break;
				}
				/* 
				* Function call for searching string in the file system.
				*/
				result = search_pattern_in_file_system(path, user_string, NULL, &count);
         			if(result == SUCCESS)
				{
					printf("\n\tSEARCHING SUCCESSFUL\n");
					if(count > 0)
					{
						printf("\nNumber of matches : %d\n", count);
					}
					else
					{
						printf("\nString not found\n");
					}
            			}
            			else
            			{
              			printf("\n\tSEARCHING FAIL\n");
            			}
				
				break;
		
			/*
			* This case is for taking absolute path from user and displaying the content
			* of that file.
			*/
			case 2:
				/*
				* Function call for displaying the content of the file.
				*/
				result = display_content();
				if(result == SUCCESS)
				{
					printf("\n\tSuccessfully displayed the content of the file\n");
				}
				else
				{
					printf("\n\tFailed in displaying the content of the file\n");
				}
				break;
				
			/*
			* This case is for taking an input string/pattern and search it in the file system
			* and displays the list of files containing the particular string/pattern. Now it
			* also gives user an option to choose any file from the list and then displays the
			* content.
			*/
			case 3:
				printf("\nPlease enter the string/pattern to search: ");
            			getchar();
            			scanf("%[^\n]",user_string);
				trim_leading_space(user_string);
				printf("len:%d\n", (int)strlen(user_string));
				if(strlen(user_string) == 0)
				{
					printf("\nPlease enter string\n");
					break;
				}
				/*
				* opening a file to store the path of all files where the string matches.
				*/
				fp = fopen("/home/saasbook/GIT/LSE/data/output.txt", "w");
				if(fp == NULL)
				{
					printf("\nFile not opened\n");
					break;
				}
				/*
				* Function call for searching string in the file system.
				*/
            			result = search_pattern_in_file_system(path, user_string, fp, &count);
         			if(result == SUCCESS)
            			{
					printf("\n\tSEARCHING SUCCESSFUL\n");
					fclose(fp);	/* closing the file */
		
					if(count == 0)
					{
						printf("\nNo Match Found\n");
						break;
					}
					printf("\nTotal number of matches : %d\n", count);  
		
					/*
					* Function call for choosing file from the list and display the content.
					*/
					result = open_user_entered_file();
					if(result == SUCCESS)
					{
						printf("\n\tSuccessfully displayed the content of the file\n");
					}
					else
					{
						printf("\n\tFailed in displaying the content of the file");
					}
            			}
            			else
            			{
              			printf("\n\tSEARCHING FAIL\n");
					fclose(fp);
            			}
				break;

			/*
			* This case is to exit from the program.
			*/
			case 4:
				printf("\n\tEXIT DONE!!!\n");
			
				/*
			       * Function call for log report.
				*/
				logging_report("EXITING: main");
			
				return SUCCESS;
			
			/*
			* Case for wrong choice.
			*/
			default:
				printf("\n\tPlease enter a valid choice");

		}	/* end of switch case */

	}	/* end of while loop */	
	return SUCCESS;	
}
