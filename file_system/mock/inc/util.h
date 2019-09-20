#ifndef __UTIL_H_
#define __UTIL_H_

	typedef struct store
	{
		char *name ;
	}Name;

	FILE *removeSpaces(char *rfile);
	int linelength(char *buf);
	int wordCount(char s[]);
	//void print_iterator(gpointer data , gpointer prefix);

#endif
