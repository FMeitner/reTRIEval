#include <stdlib.h>
#include <stdio.h>
#include "trie_func.h"
#include <string.h>


TRIE_BOOL search (char* string, struct node * root) {
    struct node * current = root;
    for(char* i = string; i[0] != '\0'; i++) {
        if(current->children[i[0]-'A'] != NULL) {
            current = current->children[i[0]-'A'];
        } else {
            return TRIE_FALSE;
            break;
        }
    }
    if(current->is_word == TRIE_TRUE) {
        return TRIE_TRUE;
    } else {
        return TRIE_FALSE;
    }
}


void insert(char* string, struct node * root, char* val) {  
    TRIE_BOOL found = TRIE_TRUE; 
    struct node * current = root;
    if(!search(string, root)) {
        for(char* i = string; i[0] != '\0'; i++) {
            if(current->children[i[0] -'A'] != NULL) {
               current = current->children[i[0]-'A'];
            } else {
                found = TRIE_FALSE;
            }
            if(found == TRIE_FALSE) {
                if(*(i+1) == '\0') {
                current->children[i[0] - 'A'] = fill_node(i[0],val,TRIE_TRUE, current);
                return;
                } else {
                current->children[i[0] - 'A'] = fill_node(i[0],val,TRIE_FALSE, current);
                current = current->children[i[0] - 'A'];
                }
            }
        }
        return;
    }
    //printf("Word already part of the TRIE \n");
    return;
}


void delete(char * string, struct node * root) {
    if(search(string,root)) {
        struct node * current = root;
        for(char* i = string; i[0] != '\0'; i++) {
            if(current->children[i[0]-'A'] != NULL) {
               current = current->children[i[0]-'A'];
            }
        }
        current->is_word = TRIE_FALSE;
        while(TRIE_TRUE) {
            for(int i = 0; i < ALPHABET_SIZE; i++) {
                if(current->children[i] != NULL) {
                    return;
                } 
            }
            char tmp = current->key;
            current = current->parent;
            current->children[tmp-'A'] = NULL;
            //printf("Node %c deleted \n", tmp);
        }
    }
    //printf("Word not found \n");
    return;
}



void free_trie(struct node * root) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
    return;
}