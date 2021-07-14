#include "trie_node.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct node* create_node() {
    struct node* new = calloc(sizeof(struct node), 1);
    new->key = ' ';
    new->children = calloc(sizeof(struct node*), 4);
    new->child_size = 4;
    new->is_word = TRIE_FALSE;
    new->value = NULL;
    new->parent = NULL;
    new->no_of_children = 0;
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
    parent->no_of_children++;
    for(int i = 0; i < parent->child_size; i++) { 
        if(parent->children[i] == NULL)
        {
            parent->children[i] = empty;
            break;
        }
        if(i+1 == parent->child_size) {
            i = 0;
            parent->child_size= parent->child_size * 2;
            parent->children = reallocarray(parent->children,parent->child_size,sizeof(struct node*));
        } 
    }
    return empty;
}