CC=gcc
CFLAGS=-Wall -Wextra -pedantic
#if you don't like or don't want gcc, feel free to change CC

all: example grepline

grepline:
	$(CC) $(CFLAGS) -c grepline.c

example: grepline
	$(CC) $(CFLAGS) grepline.o main.c -o example

getline:
	$(CC) $(CFLAGS) -DGNU_GETLINE main.c -o getline

beta:
	$(CC) $(CFLAGS) -c grepline2.c
	$(CC) $(CFLAGS) grepline2.o main.c -o example-beta

clean:
	rm -f grepline.o example grepline2.o example-beta
