#define T int
#include "linkedlist.h"

int main() {
    lnode_int* head=new_lnode_int(0);
    lnode_int* holder=head;
    for (int i=0;i<10;i++) {
        lnode_int* new_node=new_lnode_int(0);
        holder->next=new_node;
    }
    free(head);
}

#undef T