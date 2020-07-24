#include "parser.h"
#include "string_utils.h"
#include "list.h"
#include "map.h"
#include "eliza_state.h"
#include "rule.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

static const char *no_match_key = "xnone";

enum
{
  MAX_INPUT_LENGTH = 256
};


/*
 * Tokenizes input string const_input, replacing words using the
 * synonyms in eliza. If succesful *buffer is assigned an array of
 * pointers to each token. The return value is the number of tokens.
 * Both the buffer, and the memory for each token need to be called with
 * free() after use.
 *
 */

static int tokenize_and_rewrite(struct eliza_state *eliza, const char* const_input, char ***output)
{
  assert(eliza != NULL);
  assert(const_input != NULL);
  assert(output != NULL);

  char *const input = clone(const_input);
  char **tokens;

  const int token_count = tokenize(&tokens, input);
  for(int index = 0; index < token_count; ++index)
  {
    make_lowercase(tokens[index]);

    char *replacement = (char *) map_lookup(&eliza->synonyms, tokens[index]);

    if (replacement == NULL)
      tokens[index] = clone(tokens[index]);
    else
      tokens[index] = clone(replacement);
  }

  free(input);
  *output = tokens;
  return token_count;
}


/*
 * Frees token list allocated with tokenize_and_rewrite().
 *
 */

static void free_rewritten(char **tokens, const int count)
{
  assert(tokens != NULL);

  for(int i = 0; i < count; ++i)
    free(tokens[i]);

  free(tokens);
}


/*
 * Prompt for user if user==1 else prompt for ELIZA.
 *
 */

static void prompt(int user)
{
  if (user)
    printf("USER> ");
  else
    printf("ELIZA> ");

  fflush(stdout);
}


/* Returns true if the string is a token suggesting the user wants to
 * exit the session.
 *
 */

static int is_exit(struct eliza_state *eliza, const char *str)
{
  assert(eliza != NULL);
  assert(str != NULL);

  char* lowercase = clone(str);
  make_lowercase(lowercase);

  const int result = map_contains(&eliza->quit_words, lowercase);
  free(lowercase);

  return result;
}


/* Start the conversation with the user */

static void begin(struct eliza_state *eliza)
{
  assert(eliza != NULL);

  prompt(0);
  printf("%s\n", eliza->begin);
  prompt(1);
  fflush(stdout);
}


/* End the conversation with the user */

static void depart(struct eliza_state *eliza)
{
  prompt(0);
  printf("%s\n", eliza->end);
  fflush(stdout);
}


/* The main I/O loop between the user and eliza */

static void interactive_loop(struct eliza_state *eliza)
{
  begin(eliza);

  char buffer[MAX_INPUT_LENGTH];
  while(fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    trim_newline(buffer);

    if (is_exit(eliza, buffer))
    {
      depart(eliza);
      break;
    }

    char *input = rewrite_string(&eliza->prereplace, buffer);
    char **tokens;
    const int token_count = tokenize_and_rewrite(eliza, input, &tokens);

    struct list applicable_rules;
    list_init(&applicable_rules);
    for(int token_index = 0; token_index < token_count; ++token_index)
      find_rules(eliza, tokens[token_index], input, &applicable_rules);

    if (list_empty(&applicable_rules))
      find_rules(eliza, no_match_key, input, &applicable_rules);

    if (!list_empty(&applicable_rules))
    {
      struct rule *rule = choose_rule(&applicable_rules);
      char *out;
      if (rule_apply(eliza, rule, input, &out) == 0)
      {
        prompt(0);
        printf("%s\n", out);
        free(out);
        fflush(stdout);
      }
    }
    else
    {
      printf("<failed to find *any* usable rule>");
    }

    list_destroy(&applicable_rules);
    free_rewritten(tokens, token_count);
    free(input);
    prompt(1);
  }
}

int main(void)
{
  struct eliza_state eliza;
  eliza_init(&eliza);
  const int result = parse_eliza_script(&eliza, "./script");

  if (result != 0)
    fprintf(stderr, "Unable to load rules from file.");

  interactive_loop(&eliza);
  eliza_destroy(&eliza);

  return EXIT_SUCCESS;
}
