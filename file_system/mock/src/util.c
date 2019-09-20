/******************************************************************************
*
*  FILE NAME	: util.c
*
*  DESCRIPTION: This is the file 
*
*
*	DATE	      	NAME	        REFERENCE	REASON
*	23/03/2018    Deepa Kumari 	 MOCK    	TEST

*  Copyright 2007, Aricent Inc.
*
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <util.h>

#define SUCCESS 1
#define FAILURE 0

FILE *removeSpaces(char *rfile)//remove spaces from file
{
	FILE *fp = NULL ;
	FILE *fp2 = NULL;
	int p ;

	fp = fopen(rfile , "r");
	if(fp == NULL)
	{
		printf( "Error while opening the file" );
		return NULL ;
	}
	else
	{
		fp2 = fopen("..//dat//spacefile" , "w");
	
		while((p = getc(fp)) !=EOF)
		{

			fputc(p , fp2);
			if(p == 32)
				{
				while((p = getc(fp)) == 32)
					{

					}
				fputc(p , fp2);
				}
		}
        rewind(fp2);
		return fp2;
	}
}	 	
	
int linelength(char *buf)//count length of each line
{
	int i ;

	for(i = 0 ; buf[i] != '\0' ; ++i);

	return i;
}


int wordCount(char s[])//count word
{
	int count = 0;
	int i;
	for( i= 0 ; s[i] != '\0' ; i++)
	{
		if(s[i] == " ")
			{
				count++;
			}
	}
	return count;
}


//void print_iterator(gpointer d , gpointer prefix) 
//{
//	 printf("%s %s\n", prefix, d);
//}
