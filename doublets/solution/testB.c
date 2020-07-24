#include "trie.h"
#include "doublets.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int asserts_ran = 0, asserts_failed = 0, tests_ran = 0, tests_failed = 0;

#define cr_assert_not(a) do { asserts_ran++; if ((a) != (false)) { printf("%s(line %d): got: %d | expected: false\n", __func__, __LINE__, a); asserts_failed++; } } while (0)

#define cr_assert(a) do { asserts_ran++; if ((a) != (true)) { printf("%s(line %d): got: %d | expected: true\n", __func__, __LINE__, a); asserts_failed++; } } while (0)

#define run_test(test) do { \
asserts_ran = asserts_failed = 0; test(); \
tests_ran++;\
if (asserts_failed > 0) { \
tests_failed++; \
 printf("****%s: %d asserts failed out of %d asserts\n\n", #test, asserts_failed, asserts_ran); \
 }\
} while (0)


void test_valid_step() {
  dictionary_t *dict = create_dict();
  load_from_file(dict, "words.txt");
  cr_assert_not(valid_step(dict, "WHEAT", "BAR"));
  cr_assert_not(valid_step(dict, "WHEAT", "WHEAT"));
  cr_assert(valid_step(dict, "WHEAT", "CHEAT"));
  cr_assert_not(valid_step(dict, "WHEAT", "CHEAP"));
  cr_assert_not(valid_step(dict, "TREESHIP", "TREESHOP"));
  free_dict(dict);
}

void test_valid_chain() {
  dictionary_t *dict = create_dict();
  load_from_file(dict, "words.txt");
  const char *chain[] = { "WHEAT", "CHEAT", "CHEAP", "CHEEP", "CREEP", "CREED", NULL };

  cr_assert(valid_chain(dict, (const char **)(chain)));
  chain[1] = "DHEAT";
  cr_assert_not(valid_chain(dict, (const char **)(chain)));
}

void test_find_chain() {
dictionary_t *dict = create_dict();
load_from_file(dict, "words.txt");
  const char **answer = calloc(7, sizeof(const char *));
  bool has_found_chain = find_chain(dict, "HARD", "EASY", answer, 6);
  
  cr_assert(has_found_chain);
  for (int i = 0; i < 6; i++)
    free((void *) answer[i]);

  has_found_chain = find_chain(dict, "HARD", "EASY", answer, 5);
  cr_assert_not(has_found_chain);

  free(answer);
}

void test_found_chain_is_valid() {
  dictionary_t *dict = create_dict();
  load_from_file(dict, "words.txt");
  const char **answer = calloc(7, sizeof(const char *));
  find_chain(dict, "HARD", "EASY", answer, 6);
  
  cr_assert(valid_chain(dict, answer));

  for (int i = 0; i < 6; i++)
    free((void *) answer[i]);

  free(answer);
}



void run_part_b() {
  tests_ran = 0;
  tests_failed = 0;
  run_test(test_valid_step);
  run_test(test_valid_chain);
  run_test(test_find_chain);
  run_test(test_found_chain_is_valid);
  if (tests_failed == 0) {
    printf("********************\n"
           "Part B -- WELL DONE!\n"
           "********************\n");
  } else {
    printf("****************************************************\n"
           "Part B has %d incorrect functions out of %d tested\n"
           "****************************************************\n\n", tests_failed, tests_ran);
  }
}

#ifdef TESTING

int main(int argc, char **argv) {
  run_part_b();
  return EXIT_SUCCESS;
}

#endif
