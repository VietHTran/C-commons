#define CATTER(x, y) x ## y
#define FREE(TYPE) CATTER(free_lnode_, TYPE)
#define NEW(TYPE) CATTER(new_lnode_, TYPE)
#define STRUCTDEF(TYPE) CATTER(lnode_,TYPE)
#include <stdlib.h>

typedef struct STRUCTDEF(T) {
    T value;
    struct STRUCTDEF(T)* next;
} STRUCTDEF(T);

STRUCTDEF(T)* NEW(T)(T val) {
    STRUCTDEF(T)* holder = (STRUCTDEF(T)*)malloc(sizeof(STRUCTDEF(T)));
    holder->value=val;
    return holder;
}

void FREE(T)(STRUCTDEF(T)* l) {
    STRUCTDEF(T)* holder=l;
    while (holder!=NULL) {
        STRUCTDEF(T)* i=holder;
        holder=holder->next;
        free(i);
    }
}
