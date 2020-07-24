#ifndef MAP_H
#define MAP_H

struct map_node;
struct map
{
  struct map_node* root;
};

void map_init(struct map* m);
int map_insert(struct map* m, const char *key, void *value);
int map_contains(struct map* m, const char *key);
void *map_lookup(struct map *m, const char *key);
void map_apply_elems(struct map *m, void (*function)(void *));
void map_destroy(struct map *m);

#endif
