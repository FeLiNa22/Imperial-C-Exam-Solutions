CFLAGS=-std=c99 -Wall -pedantic -Werror -g -D_POSIX_SOURCE -Wno-unused-function
LDLIBS=-lpcreposix

eliza: list.o parser.o string_utils.o rule.o map.o eliza_state.o

eliza.o: parser.h string_utils.h list.h map.h eliza_state.h rule.h

elize_state.o: eliza_state.h string_utils.h rule.h list.h map.h

list.o: list.h

parser.o: parser.h eliza_state.h string_utils.h list.h map.h rule.h

string_utils.o: string_utils.h map.h

rule.o: rule.h error_codes.h string_utils.h list.h eliza_state.h parser.h

map.o: map.h string_utils.h

clean:
	rm -rf eliza eliza.o eliza_state.o list.o parser.o string_utils.o list.o string_utils.o rule.o map.o

.PHONY: clean
