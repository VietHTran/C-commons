//Generics linked list implementation
#include <stdlib.h>

#include "../generics.h"
#define FREE(TYPE_NAME) CAT(fll_, TYPE_NAME)
#define ALLOC_FREE(TYPE_NAME) CAT(afll_, TYPE_NAME)
#define MAKE(TYPE_NAME) CAT(mkll_, TYPE_NAME)
#define NODE(TYPE_NAME) CAT(ll_,TYPE_NAME)

#ifdef STR
#include "../stringutils/strutils.h"
#endif

typedef struct NODE(TN) {
    T value;
    struct NODE(TN)* next;
} NODE(TN);

//Create a new node data storage in the memory heap and return its pointer
//declaration: ll_<typename>* mkll_<typename>(<type> value);
NODE(TN)* MAKE(TN)(T value);

//Free a chain of connected nodes in the memory
//declaration: void fll_<typename>(ll_<typename>* L)
void FREE(TN)(NODE(TN)* L);

//Free a chain of connected nodes that  uses allocated memory to store data
//declaration: void afll_<typename>(ll_<typename>* L)
void ALLOC_FREE(TN)(NODE(TN)* L);

#include "linkedlist.c"
