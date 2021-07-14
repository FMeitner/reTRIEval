#ifndef FUNC_GUARD
#define FUNC_GUARD

#include "trie_node.h"

TRIE_BOOL search(char* string,struct node * root);
void insert(char* string,struct node * root, char* val);
void delete(char* string,struct node * root);
void free_trie(struct node * root);

#endif