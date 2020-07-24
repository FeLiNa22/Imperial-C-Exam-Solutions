#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"

int main(int argc, char **argv) {
  char s[MAX_STRING_LENGTH];

  printf("Please enter a string for processing: ");
  scanf("%s", s);

  char *table = nub(s);
  printf("Derived lookup table: %s\n\n", table);

  huffman_tree_list_t *l = huffman_tree_list_build(s, table);
  assert(l != NULL);
  print_huffman_tree_list(l);

  l = huffman_tree_list_reduce(l);
  assert(l != NULL);

  huffman_tree_t *t = l->tree;
  assert(t != NULL);

  printf("\n");
  print_huffman_tree(t);

  printf("\n");
  print_huffman_tree_codes(t);

  printf("\nPlease enter a string to encode: ");
  scanf("%s", s);

  char *code = huffman_tree_encode(t, s);
  printf("\"%s\" is encoded as \"%s\"\n", s, code);

  char *decoded = huffman_tree_decode(t, code);
  printf("\"%s\" decodes to \"%s\"\n", code, decoded);

  free(decoded);
  free(code);

  huffman_tree_list_free(l);

  free(table);

  return 0;
}

