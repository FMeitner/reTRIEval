#include "trie_node.h"
#include "trie_func.h"
#include "benchmark_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define test_cases 1000000

int main() {
    time_t seedtime;
    srand(time(&seedtime));
    struct node * root = create_node();
    char* random_strings[test_cases];
    for(int i = 0; i < test_cases;i++) {
        random_strings[i] = insert_random(random_strings[i]);
    }
    clock_t strings = clock();
    for(int i = 0; i < test_cases;i++) {
        insert(random_strings[i], root, "test");
    }
    clock_t end = clock();
    free_trie(root);
    clock_t trie_free = clock();
    for(int i = 0; i < test_cases;i++) {
        free(random_strings[i]);
    }
    printf("Time to insert strings: %f\n", (((double) end - (double)strings)) / CLOCKS_PER_SEC);
    printf("Time to free data: %f\n", ((double)trie_free - (double)end) / CLOCKS_PER_SEC);
    return 0;
}