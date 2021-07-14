#include "trie_node.h"
#include "trie_func.h"
#include "example_data.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node * root = create_node();
    insert_data(root);
    int egal = system("clear");
    egal++;
    search("Gök", root);
    search("BVT", root);
    delete("MAMA", root);
    delete("M4MB", root);
    delete("MAI", root);
    free_trie(root);
    return 0;
}