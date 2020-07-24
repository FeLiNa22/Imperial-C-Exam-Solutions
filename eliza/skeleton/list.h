#ifndef LIST_H
#define LIST_H

#include <stddef.h>

struct list_elem;
typedef struct list_elem *list_iter;

struct list
{
  struct list_elem *header;
  struct list_elem *footer;
};

void list_init(struct list *l);
void list_insert(struct list *l, list_iter iter, void *value);
void list_insert_front(struct list *l, void *value);
void list_insert_back(struct list *l, void *);
list_iter list_iter_next(list_iter iter);
void *list_iter_value(list_iter iter);
void list_destroy(struct list *l);
list_iter list_begin(struct list *l); 
list_iter list_end(struct list *l);
int list_empty(struct list *l);
size_t list_size(struct list *l);
void *list_get_elem(struct list *l, size_t index);
void list_apply_elems(struct list *l, void (*function)(void*));
void list_destroy(struct list *l);

#endif
