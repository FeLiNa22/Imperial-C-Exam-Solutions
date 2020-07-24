CC      = gcc
CFLAGS  = -Wall -Werror -pedantic -g
COMMON_OBJS = image.o region.o list.o
TARGETS	= regions check_list_functions
GENERATED = output.pgm regions.txt

.PHONY: all clean

.SUFFIXES: .c .o

all: $(TARGETS)

image.o: image.h

list.o: list.h region.h typedefs.h

region.o: region.h image.h typedefs.h list.h

main.o: image.h region.h list.h typedefs.h

regions: main.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

check_list_functions.o: region.h list.h test_regions.h typedefs.h

check_list_functions: check_list_functions.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGETS) $(GENERATED)
