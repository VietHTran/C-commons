#include "../generics.h"
#define FREE(TYPE) CAT(free_lnode_, TYPE_NAME)
#define NEW(TYPE) CAT(new_lnode_, TYPE_NAME)
#define NODE(TYPE) CAT(lnode_,TYPE_NAME)
#include <stdlib.h>

typedef struct NODE(TN) {
    T value;
    struct NODE(TN)* next;
} NODE(TN);

NODE(TN)* NEW(TN)(T val) {
    NODE(TN)* holder = (NODE(TN)*)malloc(sizeof(NODE(TN)));
    holder->value=val;
    holder->next=NULL;
    return holder;
}

void FREE(TN)(NODE(TN)* l) {
    NODE(TN)* holder=l;
    while (holder!=NULL) {
        NODE(TN)* i=holder;
        holder=holder->next;
        free(i);
    }
}
