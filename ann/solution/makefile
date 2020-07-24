CC=gcc
CFLAGS=-Wall -g -pedantic -std=c99
LDLIBS=-lm

# The 4 2 arguments are random for rdata
run%: %
	./$< 4 2

check%: %
	valgrind --leak-check=full ./$< 4 2

train: train.o ann.o layer.o

rdata: rdata.o

clean:
	rm -f *.o train rdata
.PHONY: clean
