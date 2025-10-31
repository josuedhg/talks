CC=gcc
CFLAGS=-Wall -g

all: main

square.o: square.c
	$(CC) $(CFLAGS) -c square.c

main: square.o main.c
	$(CC) $(CFLAGS) -o main main.c square.o

clean:
	rm -f main square.o
