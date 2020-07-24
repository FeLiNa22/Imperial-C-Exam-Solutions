#include "trie.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
}

bool load_from_file(dictionary_t *root, const char *filename) {
  return false;
}

#ifdef DICTIONARY_MAIN

// TODO: DO NOT MODIFY THIS FUNCTION!!! Remember to run:
//  valgrind --leak-check=full --show-leak-kinds=all ./dictionary

int main (void) {
  dictionary_t *d = create_dict();
  load_from_file(d, "words.txt");
  char *wordsnotin[] = { "ALGORITHMICALLY", "COMPUTER", "TRIE", "PIXEL", "ZEROED" };
  for (int i = 0; i < 5; i++) {
    if (find(d, wordsnotin[i])) {
      printf("Should not be able to find: %s\n", wordsnotin[i]);
    }
  }
  
  char *wordsin[] = { "BRAKES", "AVOWABLE", "AMOLE", "ALBUMEN", "BUZZER" };
  for (int i = 0; i < 5; i++) {
    if (!find(d, wordsin[i])) {
      printf("Should be able to find: %s\n", wordsin[i]);
    }
  }
  
  free_dict(d);
  return EXIT_SUCCESS;
}

#endif
