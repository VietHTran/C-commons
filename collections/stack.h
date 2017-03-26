#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linkedlist.h"

#define STACK(TYPE) CAT(stack_,TYPE)
#define NEW_STACK(TYPE) CAT(new_stack_, TYPE)
#define FREE_STACK(TYPE) CAT(free_stack_, TYPE)
#define PUSH_STACK(TYPE) CAT(push_stack_, TYPE)
#define POP_STACK(TYPE) CAT(pop_stack_, TYPE)
#define PEEK_STACK(TYPE) CAT(peek_stack_, TYPE)
#define EMPTY_STACK(TYPE) CAT(is_empty_stack_, TYPE)

struct STACK(T) {
    NODE(T)* value;
    int length;
};

typedef struct STACK(T) STACK(T);

STACK(T)* NEW_STACK(T)(){
    STACK(T)* S=(STACK(T)*)malloc(sizeof(STACK(T)));
    S->value=NULL;
    return S;
}

void PUSH_STACK(T)(STACK(T)* S, T value) {
    assert(S != NULL);

    NODE(T)* holder=NEW(T)(value);
    holder->value=value;
    holder->next=S->value;
    S->value=holder;

}

T POP_STACK(T)(STACK(T)* S) {
    assert(S!=NULL && S->value!=NULL);

    NODE(T)* holder=S->value;
    T val=holder->value;

    S->value=S->value->next;
    free(holder);

    return val;
}

T PEEK_STACK(T)(STACK(T)* S) {
    assert(S!=NULL && S->value!=NULL);
    return S->value->value;
}

bool EMPTY_STACK(T)(STACK(T)* S) {
    return S->value==NULL;
}

void FREE_STACK(T)(STACK(T)* S) {
    assert(S!=NULL);

    if (EMPTY_STACK(T)(S)) {
        free(S);
        return;
    }

    FREE(T)(S->value);
    free(S);
}
