#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 If it's not shipped with this software, find it yourself.
 *****************************************************************************/

size_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	size_t len = 0;
	size_t offset = ftell(stream);
	char trash = 0;
	char * buf = NULL;
	char sizeofnewline = 0;
	if(lineptr != NULL)
	{
		free(*lineptr);
	}
	do
	{
/* CRLF? Into the trash it goes */
		trash = fgetc(stream);
		if(trash != '\r')
		{
			++len;
		}
		else
		{
			++sizeofnewline;
		}
	}
	while(!feof(stream) && trash != '\n');
	fseek(stream,offset,SEEK_SET);
	buf = malloc(len+1);
	fread(buf,len,1,stream);
	if(sizeofnewline)
	{
		trash = fgetc(stream);
	}
/* We'll now null-terminate the string! */
	buf[len-1] = '\n';
	buf[len] = '\0';
/* Plugging our input pointers up the addresses we were using */
	*n = len;
	*lineptr = buf;
	return len;
}
