CC=gcc
CFLAGS=-ggdb -Wall -Wextra -pedantic
#if you don't like or don't want gcc, feel free to change CC

all: example

grepline:
	$(CC) $(CFLAGS) -c grepline.c -o grepline.o

example: grepline
	$(CC) $(CFLAGS) grepline.o main.c -o example

getline:
	$(CC) $(CFLAGS) -DGNU_GETLINE main.c -o getline

clean:
	rm -f grepline.o example getline
