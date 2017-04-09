//linked list's methods' definitions

//Create a new node data storage in the memory heap and return its pointer
//declaration: ll_<typename>* mkll_<typename>(<type> value);
NODE(TN)* MAKE(TN)(T value) {
    NODE(TN)* holder = (NODE(TN)*)malloc(sizeof(NODE(TN)));
    T added_val;

#ifdef STR
    added_val=clone_str(value);
#else
    added_val=value;
#endif

    holder->value=added_val;
    holder->next=NULL;
    return holder;
}

//Free a chain of connected nodes in the memory
//declaration: void fll_<typename>(ll_<typename>* L)
void FREE(TN)(NODE(TN)* L) {
    NODE(TN)* holder=L;
    while (holder!=NULL) {
        NODE(TN)* i=holder;
        holder=holder->next;

#ifdef STR
        free(i->value);
#endif

        free(i);
    }
}
