/******************************************************************************
*
*  FILE NAME	: main.c
*
*  DESCRIPTION: This is the file 
*
*
*	DATE	        	NAME	        REFERENCE	REASON
*	23/03/2018         Deepa Kumari 	 MOCK    	TEST

*  Copyright 2007, Aricent Inc.
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <util.h>

#define PATH "..//dat//"
#define MAX_SIZE 100
#define MAX_INP 3
//#define CH "?-"

int main(int argc , char *argv[])//takes input from user
{
	
	int i = argc -1;
    int n =(int)argv[1];
	int ret1 = 0;
	int count = 0;

	char rfile[MAX_SIZE];
	char wfile[MAX_SIZE];
	char buf[MAX_SIZE];
	char ch = '?';
	char ch1 = '-';

	FILE *inputfile = NULL;
    FILE *outputfile = NULL;
	FILE *newInputfile = NULL;
	
	char *buf1;
	char *buf2;

	GSList *list = NULL;
	GSList *iterator = NULL;
	Name *tem = NULL;
	
	if(i != MAX_INP)
	{
		printf( "Sorry, Invalid number of arguments" );
		exit(0);
	}
	
	strcpy(rfile , PATH);
	strcpy((rfile + strlen(rfile)) , argv[2]);

	strcpy(wfile , PATH);
	strcpy((wfile + strlen(wfile)) , argv[3]);

	inputfile = fopen(rfile , "r");
	if(inputfile == NULL)
	{
		printf("Error file opening the file");
		exit(0);
	}

	
	newInputfile = removeSpaces(rfile);
    if(newInputfile == NULL)
    {
        printf("Unable to remove space");
        exit(0);
    }	
    printf("Spaces removed");
    
	while(fgets(buf , MAX_SIZE , newInputfile) != NULL)
	{
        int i = 0 ;
        
        if( i <= n )
        {		
            ret1 = linelength(buf);
	    	printf( "Total number of line = %d", ret1);

	    	if(ret1 <= 80);	
		     {		
		    	count = wordCount(buf);
		    	printf( "Total word count = %d", count);

				if(count > 3)
				{
									
					buf1 = strchr(buf , ch);
					buf2 = strchr(buf , ch1);

					if(buf1 != NULL && buf2 != NULL)
					{
						tem = (Name*)malloc(sizeof(Name));
						tem->name = (char *)calloc((strlen(buf) + 1) , sizeof(char));
						
                        strcpy(tem->name , buf );
						list = g_slist_append(list , tem );
					}
					else
					{
						continue ;
					}

				}//if
						
	    	}//if
        }
        else
        {
            break;
        }//if

	}//while
	
	// copy to outputfile

  //  GSList *copy;

  //  outputfile = fopen(wfile , "w");
  //  if(outputfile != NULL)
    //    {
      //      copy =  g_slist_copy_deep(list , (GCopyFunc)g_Copy , NULL);
      //  }        



    //	for(iterator = list ; iterator ; iterator = iterator->next )
	//	{
	//         printf( "<line i> %s ", ((Name *)(iterator->data))->name);
    //   	} 

	
	return 0;
	
}
