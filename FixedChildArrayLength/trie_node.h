#ifndef NODE_GUARD
#define NODE_GUARD

#define TRIE_BOOL int
#define TRIE_FALSE 0
#define TRIE_TRUE 1

struct node {
    char key;
    struct node** children;
    int child_size;   
    int is_word;     // true wenn gültiges Wort
    char* value;    // String in Node falls Wort
    struct node* parent;
    int no_of_children;
};

struct node * create_node();
struct node * fill_node(char key, char* value, TRIE_BOOL word, struct node* parent);

#endif