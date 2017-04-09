//Generics stack implementation
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linkedlist.h"

#define STACK(TYPE_NAME) CAT(stk_,TYPE_NAME)
#define MAKE_STACK(TYPE_NAME) CAT(mkstk_, TYPE_NAME)
#define FREE_STACK(TYPE_NAME) CAT(fstk_, TYPE_NAME)
#define PUSH_STACK(TYPE_NAME) CAT(pstk_, TYPE_NAME)
#define POP_STACK(TYPE_NAME) CAT(rmstk_, TYPE_NAME)
#define PEEK_STACK(TYPE_NAME) CAT(pkstk_, TYPE_NAME)
#define EMPTY_STACK(TYPE_NAME) CAT(estk_, TYPE_NAME)

//stack definition
struct STACK(TN) {
    NODE(TN)* value;
    int length;
};

typedef struct STACK(TN) STACK(TN);

//creates a new storage for stack data structure in the heap memory and returns its pointer
//declaration: stk_<typename>* mkstk_<typename>();
STACK(TN)* MAKE_STACK(TN)();

//pushes new value into stack
//declaration: void pstk_<typename>(stk_<typename>* S, <type> value);
void PUSH_STACK(TN)(STACK(TN)* S, T value);

//gets the latest value of the stack and removes it fromt the stack
//declaration: <type> rmstk_<typename>(stk_<typename>* S);
T POP_STACK(TN)(STACK(TN)* S);

//gets the latest value of the stack without removing it
//declaration: <type> pkstk_<typename>(stk_<typename>* S);
T PEEK_STACK(TN)(STACK(TN)* S);

//checkes if stack is empty from the memory
//declaration: bool estk_<typename>(stk_<typename>* S);
bool EMPTY_STACK(TN)(STACK(TN)* S);

//frees stack and its elements
//declaration: void fstk_<typename>(stk_<typename>* S)
void FREE_STACK(TN)(STACK(TN)* S);

#include "stack.c"
