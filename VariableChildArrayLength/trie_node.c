#include "trie_node.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

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

    if((parent->no_of_children)+1 == parent->child_size) { 
        parent->child_size= parent->child_size * 2;
        parent->children = reallocarray(parent->children,sizeof(struct node*),parent->child_size);
        memset(&(parent->children[parent->no_of_children]),0,(parent->child_size) / 2);
    }
    parent->children[parent->no_of_children] = empty;
    parent->no_of_children++;
   
    return empty;
}