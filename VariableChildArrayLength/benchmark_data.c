#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include "trie_func.h"
#include <stdio.h>

char* insert_random(char* string) {
    int length = (rand() % 14 + 2 );
    string = malloc(length);
    for(int i = 0; i < length; i++) {
        string[i] = (rand() % 26) + 'A';
    }
    string[length] = '\0';
    return string;
}
