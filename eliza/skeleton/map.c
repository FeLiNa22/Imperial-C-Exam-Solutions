#include "string_utils.h"
#include "map.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct map_node
{
  char *key;
  void *value;
  struct map_node *left;
  struct map_node *right;
};


static void *map_alloc_node(void);
static void map_destroy_node(struct map_node *node);
static struct map_node *map_insert_internal(struct map_node *node, const char *key, void *value, int *result);
static int map_contains_internal(struct map_node *node, const char *key);
static void *map_lookup_internal(struct map_node *node, const char *key);
static void map_destroy_internal(struct map_node *node);
static void map_apply_elems_internal(struct map_node *node, void (*function)(void *));


/* Recursive Helper method that inserts the mapping from key to value
 * into the subtree node. If the key is not present, a new mapping is
 * created and *result is set to 1. Otherwise *result is set to 0.
 *
 * If a new mapping is inserted, the supplied key must be duplicated.
 */

struct map_node *map_insert_internal(struct map_node *node, const char *key, void *value, int *result)
{

 /* YOU SHOULD DELETE THE CONTENTS OF THIS FUNCTION AND REPLACE IT WITH
  * YOUR ANSWER TO PART 2, QUESTION 1.
  */

  fprintf(stderr, "map_insert_internal() unimplemented.\n");
  return NULL;
}


/* Applies the given function pointer to every *value* in the map */

void map_apply_elems(struct map *m, void (*function)(void *))
{
 /* YOU SHOULD DELETE THE CONTENTS OF THIS FUNCTION AND REPLACE IT WITH
  * YOUR ANSWER TO PART 3, QUESTION 1.
  */
}


/* Allocates a struct map_node */

void *map_alloc_node(void)
{
  struct map_node *node = malloc(sizeof(struct map_node));

  if (node == NULL)
  {
    perror("map_alloc_node");
    exit(EXIT_FAILURE);
  }

  node->left = NULL;
  node->right = NULL;

  return node;
}

/* Frees a struct map_node */

void map_destroy_node(struct map_node *node)
{
  free(node);
}


/* Recursive helper method that checks to see if key is contained within
 * the subtree specified by node.
 */

int map_contains_internal(struct map_node *node, const char *key)
{
  if (node == NULL)
  {
    return 0;
  }
  else if (strcmp(key, node->key) == 0)
  {
    return 1;
  }
  else if (strcmp(key, node->key) < 0)
  {
    return map_contains_internal(node->left, key);
  }
  else
  {
    return map_contains_internal(node->right, key);
  }
}

/* Recursive helper method that returns the value key maps to if it is
 * present in the subtree node. NULL is returned is the key is not
 * present in the map
 */

void *map_lookup_internal(struct map_node *node, const char *key)
{
  if (node == NULL)
    return NULL;

  if (strcmp(key, node->key) == 0)
  {
    return node->value;
  }
  else if (strcmp(key, node->key) < 0)
  {
    return map_lookup_internal(node->left, key);
  }
  else
  {
    return map_lookup_internal(node->right, key);
  }
}


/* Recursive method that destroys memory allocated by the map for
 * subtree node
 * */

void map_destroy_internal(struct map_node *node)
{
  if (node == NULL)
    return;

  map_destroy_internal(node->left);
  map_destroy_internal(node->right);
  free(node->key);
  map_destroy_node(node);
}


/* Initialises a struct map */

void map_init(struct map* m)
{
  m->root = NULL;
}


/* Inserts mapping from key to value into the map is key is not already
 * present. Returns 0 if the key was already present and value was not
 * inserted, otherwise a non-zero value. */

int map_insert(struct map* m, const char *key, void *value)
{
  assert(m != NULL);
  assert(key != NULL);

  int result;
  m->root = map_insert_internal(m->root, key, value, &result);
  return result;
}


/* Returns a non-zero value if the map contains the specified key,
 * otherwise, returns 0. */

int map_contains(struct map *m, const char *key)
{
  return map_contains_internal(m->root, key);
}


/* Returns the value associated with the specified key. If the key is
 * not present in the map, returns NULL.
 */

void *map_lookup(struct map *m, const char *key)
{
  return map_lookup_internal(m->root, key);
}


/* Deallocates memory held by the map */

void map_destroy(struct map* m)
{
  map_destroy_internal(m->root);
}
