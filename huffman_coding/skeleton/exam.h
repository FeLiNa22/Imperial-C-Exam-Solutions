#ifndef __EXAM_H
#define __EXAM_H

#include <stdlib.h>

enum { MAX_STRING_LENGTH = 128 };
enum { MAX_CODE_LENGTH = 128 };

typedef struct huffman_tree {
  int count;
  char letter;
  struct huffman_tree *left, *right;
} huffman_tree_t;

typedef struct huffman_tree_list {
  huffman_tree_t *tree;
  struct huffman_tree_list *next;
} huffman_tree_list_t;

void print_huffman_tree(const huffman_tree_t *);
void print_huffman_tree_codes(const huffman_tree_t *);
void print_huffman_tree_list(const huffman_tree_list_t *);
void huffman_tree_free(huffman_tree_t *);
void huffman_tree_list_free(huffman_tree_list_t *);

int contains(char *s, char c);
int frequency(char *s, char c);
char *nub(char *);
huffman_tree_list_t *huffman_tree_list_add(huffman_tree_list_t *,
                                            huffman_tree_t *);

huffman_tree_list_t *huffman_tree_list_build(char *, char *);
huffman_tree_list_t *huffman_tree_list_reduce(huffman_tree_list_t *);
char *huffman_tree_encode(huffman_tree_t *, char *);
char *huffman_tree_decode(huffman_tree_t *, char *);

#endif
