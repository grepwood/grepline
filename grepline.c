#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013-2023, Michael Dec
 This library is licensed Stainless License 1.0 adapted for BSD 3-Clause "New"
 or "Revised" License, because I will never consent for this to be re-written
 in Rust. You write in Rust then go write something original instead of butting
 into everyone's projects and rewriting everything. Please do something more
 meaningful with your life.
 *****************************************************************************/

size_t grepline(char **lineptr, size_t *n, FILE * stream)
{
	size_t len = 0;
	size_t offset = ftell(stream);
	char trash = 0;
	char * buf = NULL;
	char sizeofnewline = 0;
/* Cleaning up after previous run */
	if(lineptr != NULL){
		free(*lineptr);
	}
/* Reading the file until we suspect the line ends */
	do{
		trash = fgetc(stream);
		++len;
	}while(!feof(stream) && trash != '\n' && trash != '\r');
/* Windows and OSX newline detection */
	if(trash == '\r'){
		trash = fgetc(stream);
		if(trash == '\n'){
			++sizeofnewline; /* It's a Windows newline */
		}
	}
/* Going back and reading our line */
	fseek(stream,offset,SEEK_SET);
	buf = (char*)malloc(len+1);
	fread(buf,len,1,stream);
	if(sizeofnewline){
		trash = fgetc(stream);
	}
/* Fixing the line in memory into a null-terminated LF line */
	buf[len-1] = '\n';
	buf[len] = '\0';
/* Plugging our input pointers up the addresses we were using */
	*n = len;
	*lineptr = buf;
	return len;
}
