
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 If it's not shipped with this software, find it yourself.
 *****************************************************************************/

size_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	if(lineptr != NULL)
	{
		free(*lineptr);
	}
	size_t	len	= 0,
		last	= 0;
	char * buf	= NULL;
	do
	{
		last = len;
		++len;
		buf = realloc(buf,len);
		buf[last] = fgetc(stream);
	}
	while(!feof(stream) && buf[last] != '\n');
	if(buf[last] == EOF)
	{
		buf[last] = '\n';
	}
	*n = len;
	*lineptr = buf;
	return len;
}
