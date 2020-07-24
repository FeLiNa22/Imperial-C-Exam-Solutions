CC      = gcc
CFLAGS  = -Wall -g -pedantic -std=c99

.SUFFIXES: .c .o .h

.PHONY: all clean

all: heapsort

binaryheap.o: binaryheap.h

heapsort.o: binaryheap.h heapsort.c

heapsort: binaryheap.o  heapsort.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f heapsort