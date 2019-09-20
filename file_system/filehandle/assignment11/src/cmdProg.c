#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 2

int main(int argc , char *argv[])
{
	int i = argc - 1 ;
	int j = 1 ;
	char line[1000];

	FILE *finputFile ;
	FILE *foutputFile ;
	
	if( i > MAX_INPUT || i < MAX_INPUT)
	{
		printf( "Invalid number of arguments ");
		exit(-1);
	}
	else
	{  
		finputFile = fopen( argv[j] , "r" );
		if(finputFile == NULL )
		{
			printf( "Sorry, Not able to open the file " );
			exit(1);
		}
		else
		{
			j++;

			foutputFile = fopen( argv[j] , "w" );

			while(fgets(line , 1000 ,finputFile ) != NULL)
			{
			fprintf( foutputFile , " %s \n ", line);
			}			
		}
	}
	
	return 0;
}