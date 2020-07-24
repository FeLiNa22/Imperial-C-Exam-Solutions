#include "eliza_state.h"
#include "string_utils.h"
#include "rule.h"
#include "list.h"
#include "map.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

static void destroy_void_ptr_rule(void *vrule);

/* A wrapper function that calls destroy_rule() but takes a void* so it
 * can be called via a generic function pointer.
 *
 */

void destroy_void_ptr_rule(void *vrule)
{
  struct rule *rule = (struct rule*) vrule;
  destroy_rule(rule);
}

/* Intialises the ELIZA state structure */

void eliza_init(struct eliza_state *e)
{
  assert(e != NULL);

  e->begin = clone("<no greeting set>");
  e->end = clone("<no final statement set>");
  map_init(&e->quit_words);
  list_init(&e->rules);
  map_init(&e->prereplace);
  map_init(&e->postreplace);
  map_init(&e->synonyms);
}

/* Frees memory held by the ELIZA state structure */

void eliza_destroy(struct eliza_state *e)
{
  free(e->begin);
  free(e->end);

  map_destroy(&e->quit_words);

  list_apply_elems(&e->rules, &destroy_void_ptr_rule);
  list_apply_elems(&e->rules, &free);
  list_destroy(&e->rules);

  map_apply_elems(&e->prereplace, &free);
  map_destroy(&e->prereplace);

  map_apply_elems(&e->postreplace, &free);
  map_destroy(&e->postreplace);

  map_apply_elems(&e->synonyms, &free);
  map_destroy(&e->synonyms);
}
