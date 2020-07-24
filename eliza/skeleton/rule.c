#include "rule.h"
#include "error_codes.h"
#include "string_utils.h"
#include "list.h"
#include "eliza_state.h"
#include "parser.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <pcreposix.h>

static char *decomp_to_regex(const char* decomp);
static char* get_goto_target(struct eliza_state *eliza, char* reasmb);
static char* get_match_value(const char* str, regmatch_t match);
static char* substitute_matches(struct eliza_state *eliza,
  const char *template, const char* input, const regmatch_t *matches);

/* Transforms a decomp rule into the string representation of a regular
 * expression.
 */

char *decomp_to_regex(const char* decomp)
{
  char *out = empty_string();

  while(*decomp != '\0')
  {
    if (*decomp == '*')
    {
      out = push_string(out, "(.*)");
    }
    else if (*decomp == ' ')
    {
      out = push_string(out, " ?");
    }
    else if (*decomp == '@')
    {
      // Do nothing here to convert @token to token
    }
    else
    {
      char char_str[] = {*decomp, '\0'};
      out = push_string(out, char_str);
    }

    ++decomp;
  }
  return out;
}


/* Given a rasmb string, return the name of a goto target. Otherwise,
 * return NULL if reasmb is not a goto.
 */
char* get_goto_target(struct eliza_state *eliza, char* reasmb)
{
  char **tokens;
  char *str_temp = clone(reasmb);
  const int count = tokenize(&tokens, str_temp);
  char *result = NULL;

  if (count == 2 && strcmp(tokens[0], "goto") == 0)
    result = clone(tokens[1]);

  free(str_temp);
  free(tokens);
  return result;
}


/* Finds all rules in 'state' with keyword 'key' that match the text
 * 'text'. The result are added to the list 'out'.
 */

void find_rules(struct eliza_state *eliza, const char *key, const char *text, struct list *out)
{
  assert(eliza != NULL);
  assert(key != NULL);
  assert(out != NULL);

  for(list_iter rule_iter = list_begin(&eliza->rules);
      rule_iter != list_end(&eliza->rules);
      rule_iter = list_iter_next(rule_iter))
  {
    struct rule *rule = (struct rule*) list_iter_value(rule_iter);
    if (strcmp(rule->key, key) == 0 && rule_applies(eliza, rule, text))
    {
      char *next = get_goto_target(eliza, rule->reasmb);
      if (next == NULL)
      {
        list_insert_front(out, rule);
      }
      else
      {
        find_rules(eliza, next, text, out);
        free(next);
      }
    }
  }
}


/* Returns a non-zero value if the supplied rule matches the supplied
 * text, 0 otherwise.
 */

int rule_applies(struct eliza_state *eliza, struct rule* rule, const char *text)
{
  assert(eliza != NULL);
  assert(rule != NULL);
  assert(text != NULL);

  char *decomp_regex_text = decomp_to_regex(rule->decomp);

  regex_t decomp_regex;
  if (regcomp(&decomp_regex, decomp_regex_text, REG_UTF8 | REG_NOSUB) != 0)
    return 0;

  int match_result = regexec(&decomp_regex, text, 0, 0, 0);
  regfree(&decomp_regex);
  free(decomp_regex_text);

  return (match_result == 0);
}


/* Returns the string corresponding to the regular expression match
 * match. The returned string should be freed after use.
 */

char* get_match_value(const char* str, regmatch_t match)
{
  if (match.rm_so == -1)
  {
    return empty_string();
  }
  else
  {
    const int length = match.rm_eo - match.rm_so;
    char *result = malloc(length + 1);
    memcpy(result, str+match.rm_so, length);
    result[length] = '\0';
    return result;
  }
}

/* Substitute regular expression matches into a template */

char* substitute_matches(struct eliza_state *eliza, const char *template, const char* input, const regmatch_t *matches)
{
  const size_t template_length = strlen(template);
  const char* end = template + template_length;
  char *result = empty_string();

  for(const char *pos = template; pos != end;)
  {
    if (end - pos >= 3 && pos[0] == '(' && pos[2] == ')' && pos[1] >= '0' && pos[1] <= '9')
    {
      char pos_str[] = {pos[1], '\0'};
      int match = atoi(pos_str);
      char *real_value = get_match_value(input, matches[match]);
      char *rewritten = rewrite_string(&eliza->postreplace, real_value);
      free(real_value);
      result = push_string(result, rewritten);
      free(rewritten);
      pos += 3;
    }
    else
    {
      char char_str[] = {*pos, '\0'};
      result = push_string(result, char_str);
      ++pos;
    }
  }

  return result;
}


/* Apply rule to input string str and return result in *out. If
 * application succeeds, return 0, otherwise returns a non-zero value.
 */

int rule_apply(struct eliza_state *eliza, struct rule *rule, const char *str, char **out)
{
  assert(eliza != NULL);
  assert(rule != NULL);
  assert(str != NULL);
  assert(out != NULL);

  char *decomp_regex_str = decomp_to_regex(rule->decomp);

  regex_t decomp_regex;
  regmatch_t matches[10];

  if (regcomp(&decomp_regex, decomp_regex_str, REG_UTF8) != 0)
    return REGEX_FAILURE;

  int match_result = regexec(&decomp_regex, str, sizeof(matches)/sizeof(regmatch_t), matches, 0);
  regfree(&decomp_regex);
  free(decomp_regex_str);

  if (match_result == 0)
  {
    *out = substitute_matches(eliza, rule->reasmb, str, matches);
    return 0;
  }

  return -1;
}


/* Finds the higest scoring rule in rules */

int highest_scoring_rule(struct list* rules)
{
  assert(!list_empty(rules));
  int max = INT_MIN;

  for(list_iter rule_iter = list_begin(rules);
      rule_iter != list_end(rules);
      rule_iter = list_iter_next(rule_iter))
  {
    struct rule *rule = (struct rule*) list_iter_value(rule_iter);
    if (rule->precedence > max)
      max = rule->precedence;
  }
  return max;
}


/* Chooses a rule to apply from the list rules using some metric */

struct rule *choose_rule(struct list* rules)
{
  assert(!list_empty(rules));

  struct list best_rules;
  list_init(&best_rules);

  const int best_score = highest_scoring_rule(rules);

  for(list_iter rule_iter = list_begin(rules);
      rule_iter != list_end(rules);
      rule_iter = list_iter_next(rule_iter))
  {
    struct rule *rule = (struct rule*) list_iter_value(rule_iter);
    if (rule->precedence == best_score)
      list_insert_front(&best_rules, rule);
  }

  const int rule_count = list_size(&best_rules);
  const int rule_index = rand() % rule_count;
  struct rule *chosen = list_get_elem(rules, rule_index);

  list_destroy(&best_rules);
  return chosen;
}


/* Frees the memory allocated inside a struct rule */

void destroy_rule(struct rule *rule)
{
  free(rule->key);
  free(rule->reasmb);
}
