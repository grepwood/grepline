CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=gnu89
#if you don't like or don't want gcc, feel free to change CC

all: example grepline

grepline:
	$(CC) $(CFLAGS) -c grepline.c

example: grepline
	$(CC) $(CFLAGS) grepline.o main.c -o example

beta:
	$(CC) $(CFLAGS) -c grepline-1.0.2.c -o grepline-beta.o
	$(CC) $(CFLAGS) grepline-beta.o main.c -o example-beta

clean:
	rm -f grepline.o example grepline-beta.o example-beta
