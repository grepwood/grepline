CC=gcc
CFLAGS=
#if you don't like or don't want gcc, feel free to change CC

all: example grepline

grepline:
	$(CC) $(CFLAGS) -c grepline.c

example: grepline
	$(CC) $(CFLAGS) grepline.o main.c -o example

clean:
	rm -f grepline.o example
