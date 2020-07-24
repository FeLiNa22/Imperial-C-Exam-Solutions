#include "doublets.h"

#include <stdio.h>
#include <stdlib.h>

/* ------------------ YOUR CODE HERE ------------------- */

bool valid_step(dictionary_t *dict, const char *curr_word, const char *next_word) {
  return false;
}

void print_chain(const char **chain) {
}

bool valid_chain(dictionary_t *dict, const char **chain) {
  return false;
}

bool find_chain(dictionary_t *dict, const char *start_word, 
                const char *target_word, const char **chain, int max_words) {
  return false;
}

#ifdef DOUBLETS_MAIN

#define MAX_WORDS (7)

// TODO: DO NOT MODIFY THIS FUNCTION!!! Remember to run:
//  valgrind --leak-check=full --show-leak-kinds=all ./doublets

int main(void) {
  dictionary_t *dict = create_dict();
  load_from_file(dict, "words.txt");

  const char **chain = calloc(MAX_WORDS + 1, sizeof(char *));

  bool success = find_chain(dict, "HARD", "EASY", chain, MAX_WORDS);
  printf("%s a Chain of %d words!\n",
         success ? "Found" : "Couldn't find", MAX_WORDS);
  if (success) {
    print_chain(chain);
    for(int i = 0; i < MAX_WORDS; i++)
      free((void *) chain[i]);
  }

  free(chain);
  free_dict(dict);

  return EXIT_SUCCESS;
}

#endif
