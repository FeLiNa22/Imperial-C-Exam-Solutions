CC      = gcc
CFLAGS  = -Wall -g -pedantic -std=c99

.SUFFIXES: .c .o .h

.PHONY: all clean

all: program

program.o: program.c

program: program.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f program
