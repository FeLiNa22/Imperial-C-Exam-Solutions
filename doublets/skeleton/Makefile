CC = gcc
CFLAGS = -std=c99 -g -Wall -Wno-unused-value -Wno-char-subscripts
SRCS = trie.c doublets.c

all: testA testB dictionary doublets

dictionary:  clean
	$(CC) $(CFLAGS) -DDICTIONARY_MAIN -o dictionary trie.c

doublets:  clean
	$(CC) $(CFLAGS) -DDOUBLETS_MAIN -o doublets $(SRCS)

testA:  clean
	$(CC) $(CFLAGS) -DTESTING -o testA testA.c trie.c

testB:  clean
	$(CC) $(CFLAGS) -DTESTING -o testB testB.c $(SRCS)

clean:
	$(RM) -rf testA testB dictionary doublets *.o *~ *.dSYM
