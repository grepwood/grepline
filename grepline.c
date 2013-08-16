#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 Google it and read it if you want to fall asleep.
 Contact me if you would like to receive this software under another license.
 *****************************************************************************/

ssize_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	if(lineptr != NULL)
	{
		free(*lineptr);
	}
	size_t	len	= 0,
		last	= 0;
	char * buf	= NULL;
	int	c;

	do
	{
		last = len;
		++len;
		buf = realloc(buf,len);
		c = fgetc(stream);
		buf[last] = (char)c;
	}
	while(!feof(stream) && c != '\n');
	*n = strlen(buf);
	*lineptr = buf;
	return len;
}

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
	ssize_t read_length;	//signed int
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		puts("Empty file");
		exit(1);
	}
	puts("About to call grepline");
	while(!feof(fp))
	{
		read_length = grepline(&line,&length,fp);
		printf("Read line of length %d:\n%s", read_length, line);
	}
	if(line)
	{
		free(line);
	}
	fclose(fp);
	return 0;
}
