/*********************************************************************************
*	FileName : crawl_dir.c
*
*	Description : This file contains the function to search directories and other
*			sub-directories for the desired files.
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
*	FUNCTION NAME : search_pattern_in_file_system()
*
*	DESCRIPTION : This function search the string in the file system and
*			displays the path of the files in which it is found.
*
*	ARGUMENTS : dir - search directory
*		     user_pattern - user input string/pattern		     
*		     fp - file pointer to the file to store the path of all 
*			   files where the string matches.
*		     count - variable for number of matches found.
*
*	RETURNS : SUCCESS
*
******************************************************************************/

int search_pattern_in_file_system(char *dir,
				      char *user_pattern,
				      FILE *fp, 
				      int *count)
{
	DIR *dir_ptr;					/* Directory stream */
    	struct dirent *dir_info;			/* Dirent structure */
    	struct stat file_info;			/* stat structure */
    	int result = 0;				/* for checking status */
    	char path_buffer[MAX_SIZE] = {'\0'};	/* buffer to store path */
    	
	/*
	* Function call for log report.
	*/
	logging_report("ENTERING: search_pattern_in_file_system()");

	/*
	* Validation for the directory.
	*/
    	if((dir_ptr = opendir(dir)) == NULL) 
    	{
       		fprintf(stderr,"cannot open directory: %s\n", dir);
       		return 1;
	}

    	chdir(dir);	/* jumping to the search directory */
  	
	/*
	* loop for reading the directories and sub-directories.
	*/
    	while((dir_info = readdir(dir_ptr)) != NULL) 
    	{
        	lstat(dir_info->d_name, &file_info);	/* system call to get the file information */
   
		/*
		* Checking for the directory
		*/
	     	if(S_ISDIR(file_info.st_mode)) 
        	{
        		/* Ignoring '.' and '..' in the directory */
            		if((strcmp(".", dir_info->d_name) == 0) || (strcmp("..", dir_info->d_name) == 0))
			{
                		continue;
			}
          		
            		/* Recursive call for checking other sub directories */
            		result = search_pattern_in_file_system(dir_info->d_name, user_pattern, fp, count);
        	}

        	else 
		{
			/*
			* checking the file type(".txt")
			*/
			if (S_ISREG(file_info.st_mode))       //(strstr(dir_info->d_name, ".txt") != NULL)
            		{
				/* Printing all searched files */
				//printf("file: %s\n" ,dir_info->d_name); 

				/*
				* function call for matching the pattern in the files
				*/
				result = match_pattern(dir_info->d_name, user_pattern);
				if(result == SUCCESS)
				{
					*count += 1;

					/* System call to take current directory path into the temp file */
                    			system("pwd > /home/saasbook/GIT/LSE/data/temp_file.txt");
                    			
					/* Function call to read current directory path from temp_file */
					read_temp_file(path_buffer);
					
					/* Concatenating file name to the path */
                    			strcat(path_buffer, "/");
                    			strcat(path_buffer, dir_info->d_name);
					
					/* Printing the path of file */
					printf("\nMATCHED IN: %s\n", path_buffer);
					
					/* Checking file pointer */
					if(fp != NULL)
					{
						fprintf(fp, "%s\n", path_buffer);	/* Writing path in the file */ 
					}
				}
            		}
    		}
	}	/* End of while loop */

    	chdir("..");		/* jumping to previous directory */
    	closedir(dir_ptr);	/* closing the directory stream */

	/*
	* Function call for log report.
	*/
	logging_report("EXITING: search_pattern_in_file_system()");
	
	return SUCCESS;
}
