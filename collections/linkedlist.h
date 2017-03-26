#include "../generics.h"
#define FREE(TYPE) CAT(free_lnode_, TYPE)
#define NEW(TYPE) CAT(new_lnode_, TYPE)
#define NODE(TYPE) CAT(lnode_,TYPE)
#include <stdlib.h>

typedef struct NODE(T) {
    T value;
    struct NODE(T)* next;
} NODE(T);

NODE(T)* NEW(T)(T val) {
    NODE(T)* holder = (NODE(T)*)malloc(sizeof(NODE(T)));
    holder->value=val;
    holder->next=NULL;
    return holder;
}

void FREE(T)(NODE(T)* l) {
    NODE(T)* holder=l;
    while (holder!=NULL) {
        NODE(T)* i=holder;
        holder=holder->next;
        free(i);
    }
}
