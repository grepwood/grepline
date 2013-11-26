#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013, Michael Dec
 This library is licensed under 3 clause BSD license.
 If it's not shipped with this software, find it yourself.
 *****************************************************************************/

size_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	size_t	len	= 0,
		last	= 0;
	char * buf	= NULL;

	if(lineptr != NULL)
	{
		free(*lineptr);
	}

	do
	{
		last = len;
		++len;
		buf = realloc(buf,len);
		buf[last] = fgetc(stream);
	}
	while(!feof(stream) && buf[last] != '\n' && buf[last] != '\r');
	if(buf[last] == EOF)
	{
		buf[last] = '\n';
/* costanza.jpg
 * > 2013
 * > Carriage Return in standard output */
	}
	*n = len;
	*lineptr = buf;
	return len;
}
