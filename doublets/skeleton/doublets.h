#ifndef __DOUBLETS_H__
#define __DOUBLETS_H__

#include <stdbool.h>
#include <ctype.h>

#include "trie.h"

bool valid_step(dictionary_t *dict,
                const char *curr_word, const char *next_word);

void print_chain(const char **chain);

bool valid_chain(dictionary_t *dict, const char **chain);

bool find_chain(dictionary_t *dict, const char *start_word, 
                const char *target_word, const char **chain, int max_words);

#endif /* __DOUBLETS_H__ */
