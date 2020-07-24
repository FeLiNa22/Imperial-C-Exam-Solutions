#ifndef RULE_H
#define RULE_H

#include <string.h>

struct eliza_state;
struct list;

struct rule
{
  char *key;
  char *decomp;
  char *reasmb;
  int precedence;
};

int rule_apply(struct eliza_state *eliza, struct rule *rule, const char *str, char **out);
int rule_applies(struct eliza_state *eliza, struct rule* rule, const char *text);
void find_rules(struct eliza_state *eliza, const char *key, const char *text, struct list *out);
int highest_scoring_rule(struct list* rules);
struct rule *choose_rule(struct list* rules);
void destroy_rule(struct rule *rule);

#endif
