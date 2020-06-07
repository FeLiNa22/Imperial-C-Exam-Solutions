#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
/* ========================================================= */

/* Creates and initialises a new Trie node. */
dictionary_t *create_node(void);

/* Frees the resources allocated to a dictionary. */
void free_node(dictionary_t *root);

/* Returns true if word is in trie starting at node */
bool find(dictionary_t *root, const char *word);

/* Inserts word into trie starting at node */
bool insert(dictionary_t *root, const char *word);

/* Build a trie starting at node with the words listed in file */
bool load_from_file(dictionary_t *root, const char *filename);

#endif /* __DICTIONARY_H__ */
