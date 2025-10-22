#include <stdio.h>
#include <stdlib.h>
#ifdef GNU_GETLINE
#define grepline getline
#else
#include "grepline.h"
#endif /*GNU_GETLINE*/

/******************************************************************************
 Copyright 2013-2025, Michael Dec
 This demo program is dual licensed. For all intents and purposes, this demo
 program is licensed under BSD 3-Clause "New".

 If your use case is looking forward to including this demo program in a project
 that uses Rust programming language, or is written in it, or you intend to
 rewrite any part of grepline in Rust programming language, then this demo
 program is licensed under Creative Commons Attribution-NoDerivatives.
 *****************************************************************************/

int main(int argc, char *argv[]) {
	FILE * fp;
	char * line = NULL;
	size_t length = 0;
	size_t read_length;

	if(argc != 2) {
		fputs("Please give a file\n", stderr);
		return 1;
	}

	fp = fopen(argv[1],"r");
	if(fp == NULL) {
		fputs("Could not open file\n", stderr);
		return 1;
	}
	while(!feof(fp)) {
		read_length = grepline(&line,&length,fp);
#ifdef __WIN32
		printf("Read line of length %i:\n%s", read_length, line);
#else
		printf("Read line of length %ld:\n%s", read_length, line);
#endif /*__WIN32*/
	}
	if(line != NULL) {
		free(line);
		line = NULL;
	}
	fclose(fp);
	return 0;
}
