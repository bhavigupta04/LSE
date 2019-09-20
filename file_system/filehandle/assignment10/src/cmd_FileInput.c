/******************************************************************************
*
*  FILE NAME	: cmd_FileInput.c
*
*  DESCRIPTION: This is the file that read from one file and write into other file
*
*
*	DATE	      NAME	        REFERENCE	REASON
*	3/15/2018    Deepa Kumari    Assignment   Practice

*  Copyright 2007, Aricent Inc.
*
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_INPUT 2
#define PATH "..//dat//"

int main(int argc , char *argv[]) //accept two file and read the content from one file and write into another file
{
   
	int i = argc - 1 ;
	int j = 1 ;
    int character;

	char line[MAX_SIZE];
    char in1[MAX_SIZE];
    char in2[MAX_SIZE];

	FILE *finputFile ;
	FILE *foutputFile ;
	
	if( i > MAX_INPUT || i < MAX_INPUT)
	{
		printf( "Invalid number of arguments ");
		exit(-1);
	}
	else
	{  
        strcpy(in1 , PATH);
        strcpy(in2 , PATH);

        strcpy((in1 + strlen(in1)), argv[j]);
        strcpy((in2 + strlen(in2)), argv[j+1]);

    	finputFile = fopen( in1  , "r" );
		if(finputFile == NULL )
		{
			printf( "Sorry, Not able to open the file " );
			exit(1);
		}
		else
		{
             foutputFile = fopen( in2 , "w" );
	     	 while((character = fgetc(finputFile)) != EOF)
            	{

	            	fputc(character, foutputFile);
	            	printf("%c", character);
            	}
        }
    } 
    	fclose(finputFile);
    	fclose(foutputFile);

	return 0;
}
