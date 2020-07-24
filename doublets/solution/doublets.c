#include "doublets.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

/* ------------------ YOUR CODE HERE ------------------- */

bool valid_step(dictionary_t *dict, const char *curr_word, const char *next_word) {
    if (find(dict, curr_word) && find(dict, next_word) && strlen(curr_word) == strlen(next_word)) {
        int num_non_matching_letters = 0;
        for (int i = 0; i < strlen(curr_word); i++) {
            if (curr_word[i] != next_word[i]) {
                num_non_matching_letters += 1;
            }
        }
        if (num_non_matching_letters == 1) {
            return true;
        }
    }
    return false;
}

// converts entire str to uppercase
static void stringToUpper(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = (char) toupper(string[i]);
    }
}

// converts entire str to lowercase
static void stringToLower(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = (char) tolower(string[i]);
    }
}

void print_chain(const char **chain) {
    int pos = 0;
    while (chain[pos] != NULL) {
        char temp[strlen(chain[pos])];
        strcpy(temp, chain[pos]);
        if (pos == 0 || chain[pos + 1] == NULL) {
            stringToUpper(temp);
        } else {
            stringToLower(temp);
        }
        printf("%s\n", temp);
        pos++;
    }
    printf("\n");

}


bool valid_chain(dictionary_t *dict, const char **chain) {
    int pos = 0;
    while (chain[pos] != NULL && chain[pos + 1] != NULL) {
        // check word has not been used twice over
        int i = 0;
        while (chain[i] != NULL) {
            if (strcmp(chain[i], chain[pos]) == 0 && i != pos) {
                return false;
            }
            i++;
        }
        if (!valid_step(dict, chain[pos], chain[pos + 1])) {
            return false;
        }
        pos++;
    }
    return true;
}

static char *create_link(const char *string) {
    char *link;
    if ((link = (char *) malloc(strlen(string))) == NULL) {
        perror("Error allocating memory to link");
        exit(-1);
    }
    // copies string data to heap
    strcpy(link, string);
    return link;
}


static bool find_chain_helper(dictionary_t *dict, const char *current_word, const char *target_word, const char **chain,
                              int words_used, int max_words) {
    if (words_used > max_words - 1) {
        return false;
    }
    char temp[strlen(current_word)];
    strcpy(temp, current_word);
    for (int i = 0; i < strlen(temp); i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            temp[i] = j + 'A';
            if (strcmp(temp, target_word) == 0) {
                chain[words_used] = create_link(temp);
                chain[words_used + 1] = NULL;
                return true;
            } else if (valid_step(dict, current_word, temp)) {
                chain[words_used] = create_link(temp);
                chain[words_used  + 1] = NULL;
                if (valid_chain(dict, chain)) {
                    if (find_chain_helper(dict, chain[words_used], target_word, chain, words_used + 1, max_words)) {
                        return true;
                    }
                }
                free((void *) chain[words_used]);
                chain[words_used] = NULL;
            }
        }
        temp[i] = current_word[i];
    }
    return false;
}

bool find_chain(dictionary_t *dict, const char *start_word,
                const char *target_word, const char **chain, int max_words) {
    chain[0] = create_link(start_word);
    chain[1] = NULL;
    bool answer = find_chain_helper(dict, start_word, target_word, chain, 1, max_words);
    print_chain(chain);
    return answer;
}

#ifdef DOUBLETS_MAIN

#define MAX_WORDS (7)

// TODO: DO NOT MODIFY THIS FUNCTION!!! Remember to run:
//  valgrind --leak-check=full --show-leak-kinds=all ./doublets

int main(void) {
    dictionary_t *dict = create_dict();
    load_from_file(dict, "words.txt");

    const char **chain = calloc(MAX_WORDS + 1, sizeof(char *));

    bool success = find_chain(dict, "HARD", "EASY", chain, MAX_WORDS);
    printf("%s a Chain of %d words!\n",
           success ? "Found" : "Couldn't find", MAX_WORDS);
    if (success) {
        print_chain(chain);
        for (int i = 0; i < MAX_WORDS; i++)
            free((void *) chain[i]);
    }

    free(chain);
    free_dict(dict);

    return EXIT_SUCCESS;
}

#endif
