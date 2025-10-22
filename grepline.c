#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 Copyright 2013-2025, Michał Dec

 This library is dual licensed. For all intents and purposes, this library is
 licensed under BSD 3-Clause "New".

 If your use case is looking forward to including grepline in a project that
 uses Rust programming language, or is written in it, or you intend to rewrite
 any part of grepline in Rust programming language, then grepline is licensed
 under Creative Commons Attribution-NoDerivatives.
 *****************************************************************************/

size_t grepline(char ** lineptr, size_t * n, FILE * stream) {
	size_t len = 0;
	size_t offset = ftell(stream);
	char trash = 0;
	char * buf = NULL;
	char sizeofnewline = 0;
	char keep_going = 1;

/* Cleaning up after previous run */
	if(lineptr[0] != NULL) {
		free(lineptr[0]);
		lineptr[0] = NULL;
	}

/* Reading the file until we suspect the line ends */
	while(keep_going) {
		trash = fgetc(stream);
		++len;
		keep_going = !feof(stream) && trash != '\n' && trash != '\r';
	}

/* Windows and OSX newline detection */
	if(trash == '\r'){
		trash = fgetc(stream);
		sizeofnewline += (trash == '\n'); /* It's a Windows newline */
	}

/* Going back and reading our line */
	fseek(stream, offset, SEEK_SET);
	buf = malloc(len+1);
	fread(buf, len, 1, stream);
	fseek(stream, sizeofnewline, SEEK_CUR);

/* We need to deliberately do one more read and check for EOF. Without it,
 * checking for EOF is generally unreliable. */
	offset = ftell(stream);
	trash = fgetc(stream);
	if(!feof(stream)) {
		fseek(stream, offset, SEEK_SET);
	}

/* Fixing the line in memory into a null-terminated LF line */
	buf[len-1] = '\n';
	buf[len] = '\0';

/* We need to plug these values so we stay compatible with GNU getline */
	n[0] = len;
	lineptr[0] = buf;
	return len;
}
