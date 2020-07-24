#include "parser.h"
#include "eliza_state.h"
#include "string_utils.h"
#include "list.h"
#include "map.h"
#include "rule.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 512

/* Parses the script file at location 'path' into the specified ELIZA
 * state structure.
 */

int parse_eliza_script(struct eliza_state *eliza, const char *path)
{
  assert(eliza != NULL);
  assert(path != NULL);

  const char *delims = ":";

  FILE *file = fopen(path, "r");

  if (file == NULL)
  {
    perror("parse_eliza_script");
    exit(EXIT_FAILURE);
  }

  char *key = NULL;
  char *decomp = NULL;

  char *save_ptr;
  char buffer[MAX_LINE_LENGTH];

  while(fgets(buffer, sizeof(buffer), file) != NULL)
  {
    trim_newline(buffer);
    char *start = buffer;

    while(*start == ' ' || *start == '\t')
      ++start;

    char *prefix = strtok_r(start, delims, &save_ptr);
    char *value;
    long priority;

    if (prefix == NULL)
    {
      fprintf(stderr, "Expected key-value pair: %s\n", buffer);
      continue;
    }

    value = strtok_r(NULL, delims, &save_ptr);

    if (value == NULL)
    {
      fprintf(stderr, "Couldn't find value of key: %s\n", buffer);
      continue;
    }

    while(*value == ' ')
      ++value;

    if (strcmp(prefix, "initial") == 0)
    {
      free(eliza->begin);
      eliza->begin = clone(value);
    }
    else if (strcmp(prefix, "final") == 0)
    {
      free(eliza->end);
      eliza->end = clone(value);
    }
    else if (strcmp(prefix, "quit") == 0)
    {
      map_insert(&eliza->quit_words, value, "UNUSED");
    }
    else if (strcmp(prefix, "synon") == 0)
    {
      char **tokens;
      const int count = tokenize(&tokens, value);

      for(int index = 1; index < count; ++index)
      {
        char *synonym_target = clone(tokens[0]);
        const int inserted = map_insert(&eliza->synonyms, tokens[index], synonym_target);

        if (!inserted)
          free(synonym_target);
      }

      free(tokens);
    }
    else if (strcmp(prefix, "pre") == 0)
    {
      char **tokens;
      const int count = tokenize(&tokens, value);

      char *value = empty_string();
      for(int index = 1; index < count; ++index)
      {
        value = push_string(value, tokens[index]);

        if (index + 1 < count)
          value = push_string(value, " ");
      }

      const int inserted = map_insert(&eliza->prereplace, tokens[0], value);

      if (!inserted)
        free(value);

      free(tokens);
    }
    else if (strcmp(prefix, "post") == 0)
    {
      char **tokens;
      const int count = tokenize(&tokens, value);

      char *value = empty_string();
      for(int index = 1; index < count; ++index)
      {
        value = push_string(value, tokens[index]);

        if (index + 1 < count)
          value = push_string(value, " ");
      }

      const int inserted = map_insert(&eliza->postreplace, tokens[0], value);

      if (!inserted)
        free(value);

      free(tokens);
    }
    else if (strcmp(prefix, "key") == 0)
    {
      char *save_ptr_2;
      char *key_str = strtok_r(value, " ", &save_ptr_2);

      if (key_str == NULL)
        continue;

      char *priority_str = strtok_r(NULL, " ", &save_ptr_2);

      if (priority_str == NULL)
        continue;

      free(decomp);
      decomp = NULL;

      free(key);
      key = clone(key_str);

      priority = atoi(priority_str);
    }
    else if (strcmp(prefix, "decomp") == 0)
    {
      if (key == NULL)
      {
        fprintf(stderr, "Misplaced line: %s\n", buffer);
        continue;
      }

      free(decomp);
      decomp = clone(value);
      priority = strlen(decomp);
    }
    else if (strcmp(prefix, "reasmb") == 0)
    {
      if (key == NULL || decomp == NULL)
      {
        fprintf(stderr, "Misplaced line: %s\n", buffer);
        continue;
      }

      struct rule *rule = malloc(sizeof(struct rule));
      rule->key = clone(key);
      rule->decomp = clone(decomp);
      rule->reasmb = clone(value);
      rule->precedence = priority;
      list_insert_front(&eliza->rules, rule);
    }
  }

  free(decomp);
  free(key);
  fclose(file);

  return 0;
}


