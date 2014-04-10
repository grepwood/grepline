#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/******************************************************************************
 Copyright 2013-2014, Michael Dec
 This library is licensed under 3 clause BSD license.
 If it's not shipped with this software, find it yourself.
 
 Also, this version of grepline is intended for low-memory usage and fast IO.
 *****************************************************************************/

size_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	size_t len = 0;
	uint64_t offset = ftell(stream);
	char temp;
	char skipping;
	char * buf = NULL;
	if(lineptr != NULL)
	{
		free(*lineptr);
	}
	do
	{
		temp = fgetc(stream);
		if(temp == '\r')
		{
		  skipping = fgetc(stream);
		  if(skipping == '\n')
      {
		    skipping = 2; /* Windows newling skipping parameter */
		  }
		  temp = '\n'; /* We reached the end of Windows/OSX newline */
		}
		else
		{
	    ++len;
		}
	}
	while(!feof(stream) && temp != '\n');
/* We'll now prepare our string */
	buf = malloc(len+2);
	fseek(stream,offset,SEEK_SET);
  fread(buf,len,1,stream);
  buf[len-1] = '\n';
  buf[len] = 0;
  ++len;
  if(skipping != 2) /* If this isn't Windows */
  {
    skipping = 1; /* OSX/Linux skipping parameter */
  }
  fseek(stream,skipping,SEEK_CUR); /* Skipping in the file */
/* Finally we give away length with newline and the string to caller */
	*n = len;
	*lineptr = buf;
	return len;
}
