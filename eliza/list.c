#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

struct list_elem
{
  void *value;
  struct list_elem *prev;
  struct list_elem *next;
};

static struct list_elem *list_alloc_elem(void);
static void list_free_elem(struct list_elem *elem);
static int list_is_internal(list_iter iter);

/* Allocates a list node */

struct list_elem *list_alloc_elem(void)
{
  struct list_elem *elem = malloc(sizeof(struct list_elem));
  if (elem == NULL)
  {
    perror("list_alloc_elem");
    exit(EXIT_FAILURE);
  }

  return elem;
}


/* Frees a list node */

static void list_free_elem(struct list_elem *elem)
{
  free(elem);
}


/* Check that iter points to a valid element within the list */

static int list_is_internal(list_iter iter)
{
  return iter->prev != NULL && iter->next != NULL;
}


/* Initialises a list struct */

void list_init(struct list *l)
{
  l->header = list_alloc_elem();
  l->footer = list_alloc_elem();
  l->header->prev = NULL;
  l->footer->next = NULL;
  l->header->next = l->footer;
  l->footer->prev = l->header;
}


/* Inserts item "value" into list 'l', behind iterator 'iter'. */

void list_insert(struct list *l, list_iter iter, void *value)
{
  struct list_elem *new_elem = list_alloc_elem();
  new_elem->value = value;

  new_elem->prev = iter->prev;
  new_elem->next = iter;

  iter->prev->next = new_elem;
  iter->prev = new_elem;
}


/* Inserts item 'value' at the front of the list 'l'. */

void list_insert_front(struct list *l, void *value)
{
  list_insert(l, list_begin(l), value);
}


/* Inserts item 'value' at the back of the list 'l'. */

void list_insert_back(struct list *l, void *value)
{
  list_insert(l, list_end(l), value);
}


/* Given an iterator, returns the iterator to the next item in the list
 */

list_iter list_iter_next(list_iter iter)
{
  return iter->next;
}


/* Given an iterator, returns the value pointed to by that iterator */

void *list_iter_value(list_iter iter)
{
  assert(list_is_internal(iter));
  return iter->value;
}


/* Returns an iterator pointing to the first element in the list */

list_iter list_begin(struct list *l)
{
    return l->header->next;
}


/* Returns an iterator pointing to an element *after* the final element
 * in the list.
 */

list_iter list_end(struct list *l)
{
    return l->footer;
}

/* Returns a non-zero value if the list is empty */

int list_empty(struct list *l)
{
  return list_begin(l) == list_end(l);
}


/* Returns the size of the list */

size_t list_size(struct list *l)
{
  size_t size = 0;
  for(list_iter iter = list_begin(l);
      iter != list_end(l);
      iter = list_iter_next(iter))
    ++size;

  return size;
}


/* Returns the value of the list element at index 'index' */

void *list_get_elem(struct list *l, const size_t index)
{
  size_t current_index = 0;
  for(list_iter iter = list_begin(l);
      iter != list_end(l);
      iter = list_iter_next(iter))
  {
    if (current_index == index)
      return list_iter_value(iter);

    ++current_index;
  }

  assert(0 && "Out of range index passed to list_get_elem");
  return NULL;
}


/* Deallocates memory held by the list */

void list_destroy(struct list *l)
{
  struct list_elem *elem = l->header;
  while (elem != NULL)
  {
    struct list_elem *next = elem->next;
    list_free_elem(elem);
    elem = next;
  }
}


/* Apply 'function' to all elements in the list */

void list_apply_elems(struct list *l, void (*function)(void*))
{
  for(list_iter iter = list_begin(l);
      iter != list_end(l);
      iter = list_iter_next(iter))
  {
      function(list_iter_value(iter));
  }
}
