#include <stdlib.h>
#include <stdbool.h>
#include "doublets.h"
#include "trie.h"

#define MAX_WORDS (7)

int main(void) {
  dictionary_t *dict = create_dict();
  load_from_file(dict, "words.txt");

  const char **chain = calloc(MAX_WORDS + 1, sizeof(char *));
 
  // Replace `HARD` and `EASY` with your start and target words respectively
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

/* COPY YOUR CHAIN HERE
 *
 */
