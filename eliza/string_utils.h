#ifndef STRING_UTILS_H
#define STRING_UTILS_H

struct map;

void trim_newline(char *str);
char *rewrite_string(struct map *substitutions, const char* const_input);
char *empty_string(void);
char *clone(const char *str);
void make_lowercase(char *str);
int tokenize(char ***tokens, char* input);
char *push_string(char *current, const char *append);

#endif
