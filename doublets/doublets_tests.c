#include "tests.h"
#include "doublets.h"

static dictionary_t *dict;

void setup(void) {
  dict = create_dict();
  load_from_file(dict, "words.txt");
}

void teardown(void) {
  free_dict(dict);
}

TestSuite(doublets_test, .init = setup, .fini = teardown);

Test(doublets_test, valid_step) {
  cr_assert_not(valid_step(dict, "WHEAT", "BAR"));
  cr_assert_not(valid_step(dict, "WHEAT", "WHEAT"));
  cr_assert(valid_step(dict, "WHEAT", "CHEAT"));
  cr_assert_not(valid_step(dict, "WHEAT", "CHEAP"));
  cr_assert_not(valid_step(dict, "TREESHIP", "TREESHOP"));
}

Test(doublets_test, valid_chain) {
  const char *chain[] = { "WHEAT", "CHEAT", "CHEAP", "CHEEP", "CREEP", "CREED", NULL };

  cr_assert(valid_chain(dict, (const char **)(chain)));
  chain[1] = "DHEAT";
  cr_assert_not(valid_chain(dict, (const char **)(chain)));
}

Test(doublets_test, find_chain) {
  const char **answer = calloc(7, sizeof(const char *));
  bool has_found_chain = find_chain(dict, "HARD", "EASY", answer, 6);
  
  cr_assert(has_found_chain);
  for (int i = 0; i < 6; i++)
    free((void *) answer[i]);

  // =========================================

  has_found_chain = find_chain(dict, "HARD", "EASY", answer, 5);
  cr_assert_not(has_found_chain);

  free(answer);
}

Test(doublets_test, found_chain_is_valid) {
  const char **answer = calloc(7, sizeof(const char *));
  find_chain(dict, "HARD", "EASY", answer, 6);
  
  cr_assert(valid_chain(dict, answer));

  for (int i = 0; i < 6; i++)
    free((void *) answer[i]);

  free(answer);
}
