#include <stdlib.h>

#include "tests.h"
#include "trie.h"

Test(dict_test, create_dict) {
  dictionary_t *root = create_dict();
  cr_assert(root != NULL);
  free_dict(root);
}

Test(dict_test, insert) {
  dictionary_t *root = create_dict();  

  cr_assert_not(insert(root, "4ALP"));
  cr_assert_not(insert(root, "_ 3P"));
  cr_assert(insert(root, "ALPHA"));
  cr_assert(insert(root, "BETA"));

  free_dict(root);
}

Test(dict_test, find) {
  dictionary_t *root = create_dict();
  
  cr_assert_not(insert(root, "4ALP"));
  cr_assert_not(insert(root, "_ 3P"));

  cr_assert(insert(root, "ALPHA"));
  cr_assert(insert(root, "BETA"));

  cr_assert(find(root, "ALPHA"));
  cr_assert_not(find(root, "ALPH"));
  cr_assert_not(find(root, "ALPHAGAMMA"));
  cr_assert_not(find(root, "_ 3P"));

  free_dict(root);
}

Test(dict_test, load_from_file) {
  dictionary_t *root = create_dict();
  cr_assert(load_from_file(root, "words.txt"));
  free_dict(root);
}

Test(dict_test, words_loaded_from_file_can_be_found) {
  dictionary_t *root = create_dict();

  cr_assert(load_from_file(root, "words.txt"));

  FILE *fp = fopen("words.txt", "r");
  char word[MAX_WORD_SIZE];
  while (fgets(word, sizeof(word), fp) != NULL) 
    cr_assert(find(root, strtok(word, "\n")));

  free_dict(root);
}

Test(dict_test, words_not_loaded_from_file_cannot_be_found) {
  dictionary_t *root = create_dict();

  cr_assert(load_from_file(root, "words.txt"));
  char *words[] = { "ALGORITHMICALLY", "COMPUTER", "TRIE", "PIXEL", "ZEROED" };
  for (int i = 0; i < ARR_SIZE(words); i++) {
    cr_assert_not(find(root, words[i]));
  }

  free_dict(root);
}

