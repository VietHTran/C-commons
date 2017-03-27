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

struct STACK(TN) {
    NODE(TN)* value;
    int length;
};

typedef struct STACK(TN) STACK(TN);

STACK(TN)* NEW_STACK(TN)(){
    STACK(TN)* S=(STACK(TN)*)malloc(sizeof(STACK(TN)));
    S->value=NULL;
    return S;
}

void PUSH_STACK(TN)(STACK(TN)* S, T value) {
    assert(S != NULL);

    NODE(TN)* holder=NEW(TN)(value);
    holder->value=value;
    holder->next=S->value;
    S->value=holder;

}

T POP_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL && S->value!=NULL);

    NODE(TN)* holder=S->value;
    T val=holder->value;

    S->value=S->value->next;
    free(holder);

    return val;
}

T PEEK_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL && S->value!=NULL);
    return S->value->value;
}

bool EMPTY_STACK(TN)(STACK(TN)* S) {
    return S->value==NULL;
}

void FREE_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL);

    if (EMPTY_STACK(TN)(S)) {
        free(S);
        return;
    }

    FREE(TN)(S->value);
    free(S);
}
