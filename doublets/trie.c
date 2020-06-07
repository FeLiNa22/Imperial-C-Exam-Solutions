#include "trie.h"

dictionary_t *create_dict(void) {
  return create_node();
}

void free_dict(dictionary_t *root) {
  free_node(root);
}

/* ------------ YOUR CODE BELOW -------------- */

bool find(dictionary_t *root, const char *word) {
  return false;
}

bool insert(dictionary_t *root, const char *word) {
  return false;
}

dictionary_t *create_node(void) {
  return NULL;
}

void free_node(dictionary_t *root) {
  return;
}

bool load_from_file(dictionary_t *root, const char *filename) {
  return false;
}


