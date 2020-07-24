CC      = gcc
CFLAGS  = -Wall -g -std=c99

.SUFFIXES: .c .o .h

.PHONY: all clean

all: main

exam.o: exam.c exam.h

main.o: exam.h main.c

main: main.o exam.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f main
