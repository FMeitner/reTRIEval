#include "trie_node.h"
#include "trie_func.h"
#include "example_data.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node * root = create_node();
    insert_data(root);
    search("Gök", root);

    return 0;
}