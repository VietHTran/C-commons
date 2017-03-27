#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linkedlist.h"

#define QUEUE(TYPE_NAME) CAT(queue_,TYPE_NAME)
#define NEW_QUEUE(TYPE_NAME) CAT(new_queue_, TYPE_NAME)
#define FREE_QUEUE(TYPE_NAME) CAT(free_queue_, TYPE_NAME)
#define DEQUEUE(TYPE_NAME) CAT(dequeue_, TYPE_NAME)
#define ENQUEUE(TYPE_NAME) CAT(enqueue_, TYPE_NAME)
#define PEEK_QUEUE(TYPE_NAME) CAT(peek_queue_, TYPE_NAME)
#define EMPTY_QUEUE(TYPE_NAME) CAT(is_empty_queue_, TYPE_NAME)

struct QUEUE(TN) {
    NODE(TN)* tail;
    NODE(TN)* front;
    int length;
};

typedef struct QUEUE(TN) QUEUE(TN);

QUEUE(TN)* NEW_QUEUE(TN)(){
    QUEUE(TN)* S=(QUEUE(TN)*)malloc(sizeof(QUEUE(TN)));
    S->tail=NULL;
    S->front=NULL;
    return S;
}

void ENQUEUE(TN)(QUEUE(TN)* S, T value) {
    assert(S != NULL);

    NODE(TN)* holder=NEW(TN)(value);

    if (S->front==NULL) {
        S->front=holder;
    } else {
        S->tail->next=holder;
    }
    S->tail=holder;
}

T DEQUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL && S->front!=NULL);

    NODE(TN)* holder=S->front;
    T val=holder->value;

    S->front=S->front->next;
    free(holder);

    return val;
}

T PEEK_QUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL && S->front!=NULL);
    return S->front->value;
}

bool EMPTY_QUEUE(TN)(QUEUE(TN)* S) {
    return S->front==NULL;
}

void FREE_QUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL);

    if (!EMPTY_QUEUE(TN)(S)) {
        FREE(TN)(S->front);
    }

    free(S);
}
