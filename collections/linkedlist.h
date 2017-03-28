//Generics linked list implementation
#include "../generics.h"
#define FREE(TYPE_NAME) CAT(free_lnode_, TYPE_NAME)
#define NEW(TYPE_NAME) CAT(new_lnode_, TYPE_NAME)
#define NODE(TYPE_NAME) CAT(lnode_,TYPE_NAME)
#include <stdlib.h>

typedef struct NODE(TN) {
    T value;
    struct NODE(TN)* next;
} NODE(TN);

//Create a new node data storage in the memory heap and return its pointer
NODE(TN)* NEW(TN)(T val);

//Free a chain of connected nodes in the memory
void FREE(TN)(NODE(TN)* l);

#include "linkedlist.c"
