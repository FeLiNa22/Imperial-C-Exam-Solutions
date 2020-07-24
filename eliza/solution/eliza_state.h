#ifndef ELIZA_STATE_H
#define ELIZA_STATE_H

#include "list.h"
#include "map.h"

struct eliza_state
{
  char *begin;
  char *end;
  struct map quit_words;
  struct map prereplace;
  struct map postreplace;
  struct map synonyms;
  struct list rules;
};

void eliza_init(struct eliza_state *e);
void eliza_destroy(struct eliza_state *e);
void eliza_print_rules(struct eliza_state *e);

#endif
