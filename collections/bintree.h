//Generics binary tree implementation
#include <stdlib.h>

#include "../generics.h"

#define MAKE_TR(TYPE_NAME) CAT(mktr_,TYPE_NAME)
#define FREE_TR(TYPE_NAME) CAT(ftr_,TYPE_NAME)
#define ALLOC_FREE_TR(TYPE_NAME) CAT(aftr_,TYPE_NAME)
#define NODE_TR(TYPE_NAME) CAT(trnd_,TYPE_NAME)

#ifdef STR
#include "../stringutils/strutils.h"
#endif

typedef struct NODE_TR(TN) {
    T value;
    struct NODE_TR(TN)* left;
    struct NODE_TR(TN)* right;
} NODE_TR(TN);

//Create a new tree binary data storage in the memory heap and return its pointer
//declaration: trnd_<typename>* mktr_<typename>(<type> value);
NODE_TR(TN)* MAKE_TR(TN)(T value);

//Free a chain of connected tree nodes in the memory
//declaration: void ftr_<typename>(trnd_<typename> L)
void FREE_TR(TN)(NODE_TR(TN)* l);

//Free a chain of connected tree nodes whose value use allocated memory
//declaration: void aftr_<typename>(trnd_<typename> L)
void ALLOC_FREE_TR(TN)(NODE_TR(TN)* l);

#include "bintree.c"
