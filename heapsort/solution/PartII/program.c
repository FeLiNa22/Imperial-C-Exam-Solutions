#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *derived_lookup_table(char *);

int contains(char *, char);

int main(void) {

    char *s = "attack";

    printf("The initial word is: %s\n", s);

    char *table = derived_lookup_table(s);

    printf("Derived lookup table: %s\n\n", table);
    free(table);
    return EXIT_SUCCESS;
}

char *derived_lookup_table(char *s) {
    /* BUGS
     * no null check on malloc for o_end
     * o_end = o_out will cause mem leaks, as o_out cannot be freed
     * use of sizeof(s) instead of strlen(s) + 1
    //    char *out = realloc(out, o_end - o_out + 1);
     * realloc is trying to alloc to out, which is undefined
     * o_out is not even needed
     * *o_end++ changes the pointer of o_end (logical error)
     * */

    char *o_end = malloc(strlen(s) + 1);
    char *o_out = o_end;

    for (; *s != '\0'; ++s) {
        if (!contains(o_out, *s)) {
            *o_end++ = *s;
        }
    }

    char *out = realloc(o_out, strlen(o_out) + 1);
    if (out == NULL) {
        perror("out realloc error");
        exit(EXIT_FAILURE);
    }
    return out;
}


int contains(char *s, char c) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            return 1;
        }
    }

    return 0;
}
