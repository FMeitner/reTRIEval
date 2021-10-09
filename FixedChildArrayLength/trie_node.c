#include "trie_node.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>



struct node* create_node() {
    struct node* new = NULL;
    new = malloc(sizeof(struct node));
    for(int i = 0; i < ALPHABET_SIZE; i++) { 
        new->children[i] = NULL;
    }
    new->is_word = TRIE_FALSE;
    new->key = ' ';
    new->parent = NULL;
    new->value = NULL;
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        new->children[i] = NULL;
    }
    return new;
}

struct node * fill_node(char key, char* value, TRIE_BOOL word, struct node* parent) 
{
    struct node * empty = create_node();
    empty->key = key;
    if(word == TRIE_TRUE) {
        empty->is_word = word;
        empty->value = value;
    }
    empty->parent = parent;    

    parent->children[key-'A'] = empty;
    return empty;
}