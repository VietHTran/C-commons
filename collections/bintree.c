//Generics binary tree implementation

//Create a new tree binary data storage in the memory heap and return its pointer
NODE_TR(TN)* NEW_TR(TN)(T val) {
    NODE_TR(TN)* holder = (NODE_TR(TN)*)malloc(sizeof(NODE_TR(TN)));
    T added_val;

#ifdef STR
    added_val=clone_str(val);
#else
    added_val=val;
#endif

    holder->value=added_val;
    holder->left=NULL;
    holder->right=NULL;
    return holder;
}

//Free a chain of connected tree nodes in the memory
void FREE_TR(TN)(NODE_TR(TN)* l) {

#ifdef STR
    free(l->value);
#endif

    if (l->left!=NULL) {FREE_TR(TN)(l->left);}
    if (l->right!=NULL) {FREE_TR(TN)(l->right);}
    free(l);
}
