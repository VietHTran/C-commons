//Generics stack implementation
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linkedlist.h"

#define STACK(TYPE_NAME) CAT(stack_,TYPE_NAME)
#define NEW_STACK(TYPE_NAME) CAT(new_stack_, TYPE_NAME)
#define FREE_STACK(TYPE_NAME) CAT(free_stack_, TYPE_NAME)
#define PUSH_STACK(TYPE_NAME) CAT(push_stack_, TYPE_NAME)
#define POP_STACK(TYPE_NAME) CAT(pop_stack_, TYPE_NAME)
#define PEEK_STACK(TYPE_NAME) CAT(peek_stack_, TYPE_NAME)
#define EMPTY_STACK(TYPE_NAME) CAT(is_empty_stack_, TYPE_NAME)

//stack definition
struct STACK(TN) {
    NODE(TN)* value;
    int length;
};

typedef struct STACK(TN) STACK(TN);

//creates a new storage for stack data structure in the heap memory and returns its pointer
STACK(TN)* NEW_STACK(TN)();

//pushes new value into stack
void PUSH_STACK(TN)(STACK(TN)* S, T value);

//gets the latest value of the stack and removes it fromt the stack
T POP_STACK(TN)(STACK(TN)* S);

//gets the latest value of the stack without removing it
T PEEK_STACK(TN)(STACK(TN)* S);

//checkes if stack is empty from the memory
bool EMPTY_STACK(TN)(STACK(TN)* S);

//frees stack and its elements
void FREE_STACK(TN)(STACK(TN)* S);

#include "stack.c"
