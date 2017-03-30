//linked list's methods' definitions

//Create a new node data storage in the memory heap and return its pointer
NODE(TN)* NEW(TN)(T val) {
    NODE(TN)* holder = (NODE(TN)*)malloc(sizeof(NODE(TN)));
    T added_val;

#ifdef STR
    added_val=clone_str(val);
#else
    added_val=val;
#endif

    holder->value=added_val;
    holder->next=NULL;
    return holder;
}

//Free a chain of connected nodes in the memory
void FREE(TN)(NODE(TN)* l) {
    NODE(TN)* holder=l;
    while (holder!=NULL) {
        NODE(TN)* i=holder;
        holder=holder->next;
#ifdef STR
        free(i->value);
#endif

        free(i);
    }
}
