#include <stdlib.h>
#include <stdio.h>
#include "trie_func.h"
#include <string.h>

TRIE_BOOL search (char* string, struct node * root) {
    TRIE_BOOL found = TRIE_FALSE;
    struct node * found_child;
    //printf("looking for %s \n", string);

    for(int i = 0; i < root->no_of_children; i++)
    {
        if(string[0] == root->children[i]->key) {
            found = TRIE_TRUE;
            found_child = root->children[i];
            break;
        }
    }

    if(found == TRIE_TRUE) {
        if(string[1] == '\0') {
            if(found_child->is_word != TRIE_TRUE)
            {
                //printf("node %c has no value \n", string[0]);
                return TRIE_FALSE;
            }
            //printf("node %c has value %s \n", string[0], found_child->value);
            return TRIE_TRUE;
        }
        //printf("node \"%c\" found \n", string[0]);
        return search(string+1, found_child);
    }
    //printf("node %c not found \n", string[0]);
    return TRIE_FALSE;
}

void insert(char* string, struct node * root, char* val) {   
       char* current = string;
       struct node * currnode = root;
       
       while(*current != '\0') {
           TRIE_BOOL add = TRIE_TRUE;
           for(int j = 0; j < currnode->no_of_children; j++) {
                if (currnode->children[j]->key == *current) {
                    //printf("node %c already exists \n", current[0]);
                    add = TRIE_FALSE;
                    currnode = currnode->children[j];
                }
           }
        if(add == TRIE_TRUE) {
            struct node * new = fill_node(*current, "kekw", TRIE_FALSE, currnode);
            currnode = new;
            //printf("adding node %c \n", *current);
            
            if(current[1] == '\0')
            {
                new->value = val;
                new->is_word = TRIE_TRUE;
                //printf("word added \n");
            }   
        }
        current+=1;
    }
}

void delete(char * string, struct node * root) {
    //printf("Trying to remove word %s. \n", string);
    if(search(string, root) == TRIE_FALSE) {
        //printf("Word was not found so it can't be deleted. \n");
        return;
    }
    char* current = string;
    struct node * currnode = root;
    while(*current != '\0' && currnode->no_of_children != 0) {
           for(int j = 0; j < currnode->no_of_children; j++) {
               if(currnode->children[j]->key == *current) {
                    currnode = currnode->children[j];
                    current++;    
                    break;
               }
            }
        }
    currnode->is_word = TRIE_FALSE;
    //printf("Last letter of word unmarked \n");
    while(currnode->no_of_children == 0) {
        char tmp = currnode->key;
        free(currnode->children);
        currnode = currnode->parent;
        for(int i = 0; i < currnode->no_of_children; i++) {
            if(tmp == currnode->children[i]->key) {
                //printf("deleting node %c \n", currnode->children[i]->key);  
                free(currnode->children[i]);
                memmove(&(currnode->children[i]),&(currnode->children[i+1]),(currnode->no_of_children-i) * sizeof(struct node *));
                currnode->no_of_children--;
                break;
            }
        }
              
    }
}

void free_trie(struct node * root) {
    if(root == NULL) {
        return;
    }
    for(int i = 0; i < root->no_of_children; i++) {
        free_trie(root->children[i]);
    }
    free(root->children);
    free(root);
}