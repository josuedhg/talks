CC=gcc
CFLAGS=-Wall -g

all: main

main: main.c vfs.c
	$(CC) $(CFLAGS) -o main $^

clean:
	rm -f main
