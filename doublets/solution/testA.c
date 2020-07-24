#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "trie.h"

int asserts_ran = 0, asserts_failed = 0, tests_ran = 0, tests_failed = 0;

#define assert_eq(a, b) do { asserts_ran++; if ((a) != (b)) { printf("%s(line %d): got: %d | expected: %d\n", __func__, __LINE__, a, b); asserts_failed++; } } while (0)

#define assert_eq_silent(a, b) do { asserts_ran++; if ((a) != (b)) { asserts_failed++; } } while (0)

#define assert_ptr_notnull(p) do { asserts_ran++; if (p == NULL) { printf("%s(line %d): pointer should not be NULL\n", __func__, __LINE__); asserts_failed++; return; } } while (0)

#define run_test(test) do { \
asserts_ran = asserts_failed = 0; test(); \
tests_ran++;\
if (asserts_failed > 0) { \
tests_failed++; \
 printf("****%s: %d asserts failed out of %d asserts\n\n", #test, asserts_failed, asserts_ran); \
 }\
} while (0)


void test_create_dict() {
  dictionary_t *root = create_dict();
  assert_ptr_notnull(root);
  free_dict(root);
}

void test_insert() {
  dictionary_t *root = create_dict();

  assert_eq(insert(root, "4ALP"), false);
  assert_eq(insert(root, "_ 3P"), false);
  assert_eq(insert(root, "ALPHA"), true);
  assert_eq(insert(root, "BETA"), true);

  free_dict(root);
}

void test_find() {
  dictionary_t *root = create_dict();

  assert_eq(insert(root, "4ALP"), false);
  assert_eq(insert(root, "_ 3P"), false);

  assert_eq(insert(root, "ALPHA"), true);
  assert_eq(insert(root, "BETA"), true);

  assert_eq(find(root, "ALPHA"), true);
  assert_eq(find(root, "ALPH"), false);
  assert_eq(find(root, "ALPHAGAMMA"), false);
  assert_eq(find(root, "_ 3P"), false);

  free_dict(root);
}

void test_load_from_file() {
  dictionary_t *root = create_dict();
  assert_eq(load_from_file(root, "words.txt"), true);
  free_dict(root);
}

void test_words_loaded_from_file_can_be_found() {
  dictionary_t *root = create_dict();

  assert_eq(load_from_file(root, "words.txt"), true);

  FILE *fp = fopen("words.txt", "r");
  char word[MAX_WORD_SIZE];
  while (fgets(word, sizeof(word), fp) != NULL)
    assert_eq_silent(find(root, strtok(word, "\n")), true);

  free_dict(root);
}

void test_words_not_loaded_from_file_cannot_be_found() {
  dictionary_t *root = create_dict();

  assert_eq(load_from_file(root, "words.txt"), true);
  char *words[] = { "ALGORITHMICALLY", "COMPUTER", "TRIE", "PIXEL", "ZEROED" };
  for (int i = 0; i < 5; i++) {
    assert_eq(find(root, words[i]), false);
  }

  free_dict(root);
}

void run_part_a() {
  tests_ran = 0;
  tests_failed = 0;
  run_test(test_create_dict);
  run_test(test_insert);
  run_test(test_find);
  run_test(test_load_from_file);
  run_test(test_words_loaded_from_file_can_be_found);
  run_test(test_words_not_loaded_from_file_cannot_be_found);
  if (tests_failed == 0) {
    printf("********************\n"
           "Part A -- WELL DONE!\n"
           "********************\n");
  } else {
    printf("****************************************************\n"
           "Part A has %d incorrect functions out of %d tested\n"
           "****************************************************\n\n", tests_failed, tests_ran);
  }
}

#ifdef TESTING

int main(int argc, char **argv) {
	run_part_a();
	return EXIT_SUCCESS;
}

#endif

