#include <stdio.h>
#include <stdlib.h>
#include "grepline.h"

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 If it's not shipped with this software, find it yourself.
 *****************************************************************************/

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		puts("Please give a file");
		exit(1);
	}
	FILE * fp;
	char * line = NULL;
	size_t	length = 0,
		read_length;
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		puts("Empty file");
		exit(1);
	}
	while(!feof(fp))
	{
		read_length = grepline(&line,&length,fp);
#ifdef __WIN32
		printf("Read line of length %i:\n%s", read_length, line);
#else
		printf("Read line of length %ld:\n%s", read_length, line);
#endif //__WIN32
	}
	if(line)
	{
		free(line);
	}
	fclose(fp);
	return 0;
}
