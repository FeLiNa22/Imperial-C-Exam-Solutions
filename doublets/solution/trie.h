#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <stdbool.h>

#define MAX_WORD_SIZE (20)

/* Struct for a digital trie's node */
typedef struct TrieNode {

  /* The array of pointers to the children of this node */
  struct TrieNode **children; 

  /* END-OF-WORD flag, true if node represents
   * the end of a word; false by default */
  bool end_of_word;              

} dictionary_t;

dictionary_t *create_dict(void);

void free_dict(dictionary_t *dict);

dictionary_t *create_node(void);

void free_node(dictionary_t *root);

bool find(dictionary_t *root, const char *word);

bool insert(dictionary_t *root, const char *word);

bool load_from_file(dictionary_t *root, const char *filename);

#endif /* __DICTIONARY_H__ */
