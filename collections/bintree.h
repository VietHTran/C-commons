//Generics binary tree implementation
#include <stdlib.h>

#include "../generics.h"
#define FREE_TR(TYPE_NAME) CAT(free_tree_,TYPE_NAME)
#define NEW_TR(TYPE_NAME) CAT(new_tree_,TYPE_NAME)
#define NODE_TR(TYPE_NAME) CAT(tnode_,TYPE_NAME)
#define PNODE_TR(TYPE_NAME) CAT(NODE_TR(TYPE_NAME),*)

#ifdef STR
#include "../stringutils/strutils.h"
#endif

typedef struct NODE_TR(TN) {
    T value;
    struct NODE_TR(TN)* left;
    struct NODE_TR(TN)* right;
} NODE_TR(TN);

//Create a new tree binary data storage in the memory heap and return its pointer
NODE_TR(TN)* NEW_TR(TN)(T val);

//Free a chain of connected tree nodes in the memory
void FREE_TR(TN)(NODE_TR(TN)* l);

#include "bintree.c"
