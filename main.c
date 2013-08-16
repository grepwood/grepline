#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 Google it and read it if you want to fall asleep.
 Contact me if you would like to receive this software under another license.
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
	size_t length = 0;	//unsigned int
	size_t read_length;	//signed int
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