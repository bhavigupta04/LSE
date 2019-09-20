#include <stdio.h>
#include <stdlib.h>

int write_To( int count , char *argv)
{
    int j = 1;

    FILE *fin;
    FILE *fout;

    fin = fopen ( (argv+j) , "r" );
    if(fin == NULL)
    {
        printf( "Sorry, Not able to open file" );
        exit(-1);
    }
    
