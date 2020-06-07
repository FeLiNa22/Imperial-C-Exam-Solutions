#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * CopyUniqueLettersPtr( const char *, int);

int *printIntPtr(int *, long);

int contains(const char *, char);

int main(void) {
    char buffer[] = "good luck";
    char *cpybuffer = NULL;
    int *intbuffer = calloc(sizeof(buffer), sizeof(int));

    printf("The contents of buffer is: %s\n", buffer);

    cpybuffer = CopyUniqueLettersPtr(buffer, sizeof(buffer));

    intbuffer = (int *) printIntPtr(intbuffer, sizeof(buffer));

    printf("The unique letters are %s and the integer in array position 5 is: %i\n", cpybuffer, intbuffer[5]);

    return EXIT_SUCCESS;
}


// Returns 1 if character c is contained in string s, returns 0 otherwise.

int contains(const char *s, const char c) {
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}

//Copy unique number of characters from a string

char *CopyUniqueLettersPtr(const char *src, int number_letters) {
    char *temp = calloc(strlen(src) + 1, sizeof(char));
    if (temp == NULL) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    char *dst = temp;

    for (int i = 0; *src != '\0' && i < number_letters; ++src, ++i) {
        if (!contains(temp, *src)) {
            *dst++ = *src;
        }
    }

    dst = realloc(temp, strlen(temp) + 1);
    return dst;
}

//initialise integer array and prints each item
int *printIntPtr(int *intPtr, long size) {
    int *intptr = intPtr;
    if (intptr != NULL) {
        for (int i = 0; i < size; ++i) {
            intptr[i] = i;
            printf("The integer in position %i is: %i\n", i, intptr[i]);
        }
    }
    return intptr;
}
