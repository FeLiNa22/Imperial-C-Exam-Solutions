#ifndef __DOUBLETS_H__
#define __DOUBLETS_H__

#include <stdbool.h>
#include <ctype.h>

#include "trie.h"

/* Returns true if step from start_word to next_word is valid wrt dict */
bool valid_step(dictionary_t *dict, const char *curr_word, const char *next_word);

/* Prints chain to standard output */
void print_chain(const char **chain);

/* Returns true if chain is valid */
bool valid_chain(dictionary_t *dict, const char **chain); 

/* Returns true if a chain of (at most) max_words words can be created
 * from start_word to target_word, and populates chain with pointers to 
 * heap-allocated NULL-terminated strings. */
bool find_chain(dictionary_t *dict, const char *start_word, 
                const char *target_word, const char **chain, int max_words);

#endif /* __DOUBLETS_H__ */
