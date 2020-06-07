CC      = gcc
CFLAGS  = -Wall -g -pedantic -std=c99
LIBS = -lm

.SUFFIXES: .c .o .h

.PHONY: all clean

all: dragon

image.o: image.h

dragon.o: image.h dragon.h dragon.c

dragon: image.o  dragon.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f dragon
