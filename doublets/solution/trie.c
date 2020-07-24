#include "trie.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

dictionary_t *create_dict(void) {
    return create_node();
}

void free_dict(dictionary_t *root) {
    free_node(root);
}

/* ------------ YOUR CODE BELOW -------------- */

bool find(dictionary_t *root, const char *word) {
    int alpha_pos = word[0] - 'A';
    if (strlen(word) == 0 && root->end_of_word) {
        return true;
    } else if (alpha_pos > 25 || alpha_pos < 0) {
        return false;
    } else if (root->children[alpha_pos] != NULL) {
        return find(root->children[alpha_pos], word + 1);
    } else {
        return false;
    }
}


bool insert(dictionary_t *root, const char *word) {
    int alpha_pos = (char) word[0] - 'A';
    if (strlen(word) == 0 && !root->end_of_word) {
        root->end_of_word = true;
        return true;
    } else if (alpha_pos > 25 || alpha_pos < 0) {
        return false;
    } else if (root->children[alpha_pos] == NULL) {
        struct TrieNode *newNode = create_node();
        root->children[alpha_pos] = newNode;
        return insert(root->children[alpha_pos], &word[1]);
    } else if(root->children[alpha_pos] != NULL){
        return insert(root->children[alpha_pos], &word[1]);
    }else {
        return false;
    }
}

dictionary_t *create_node(void) {
    struct TrieNode *node;
    if ((node = (struct TrieNode *) malloc(sizeof(struct TrieNode))) == NULL) {
        perror("Cannot allocate memory for node");
        exit(-1);
    }
    node->children = calloc(ALPHABET_SIZE, sizeof(struct TrieNode *));
    if(node->children == NULL){
        perror("Cannot allocate memory for node children");
        exit(-1);
    }
    node->end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void free_node(dictionary_t *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            free_node(root->children[i]);
        }
    }
    free(root->children);
    free(root);
}

bool load_from_file(dictionary_t *root, const char *filename) {
    FILE *fptr;
    if((fptr = fopen(filename,"r"))== NULL){
        perror("Error opening file");
        return false;
    }
    char WORD[MAX_WORD_SIZE];
    while(fgets(WORD,MAX_WORD_SIZE,fptr)){
        insert(root, strtok(WORD, "\n"));
    }
    fclose(fptr);
    return true;
}

#ifdef DICTIONARY_MAIN

// TODO: DO NOT MODIFY THIS FUNCTION!!! Remember to run:
//  valgrind --leak-check=full --show-leak-kinds=all ./dictionary

int main(void) {
    dictionary_t *d = create_dict();
    load_from_file(d, "words.txt");
    char *wordsnotin[] = {"ALGORITHMICALLY", "COMPUTER", "TRIE", "PIXEL", "ZEROED"};
    for (int i = 0; i < 5; i++) {
        if (find(d, wordsnotin[i])) {
            printf("Should not be able to find: %s\n", wordsnotin[i]);
        }
    }

    char *wordsin[] = {"BRAKES", "AVOWABLE", "AMOLE", "ALBUMEN", "BUZZER"};
    for (int i = 0; i < 5; i++) {
        if (!find(d, wordsin[i])) {
            printf("Should be able to find: %s\n", wordsin[i]);
        }
    }

    free_dict(d);
    return EXIT_SUCCESS;
}

#endif
