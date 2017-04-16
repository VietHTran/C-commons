//Generics binary tree implementation

//Create a new tree binary data storage in the memory heap and return its pointer
//declaration: trnd_<typename>* mktr_<typename>(<type> value);
NODE_TR(TN)* MAKE_TR(TN)(T val) {
    NODE_TR(TN)* holder = (NODE_TR(TN)*)malloc(sizeof(NODE_TR(TN)));
    holder->value=val;
    holder->left=NULL;
    holder->right=NULL;
    return holder;
}

//Free a chain of connected tree nodes in the memory
//declaration: void ftr_<typename>(trnd_<typename> L)
void FREE_TR(TN)(NODE_TR(TN)* l) {
    if (l->left!=NULL) {FREE_TR(TN)(l->left);}
    if (l->right!=NULL) {FREE_TR(TN)(l->right);}
    free(l);
}

#ifdef ALLOC_T //T use allocated memory

//Free a chain of connected tree nodes whose value use allocated memory
//declaration: void aftr_<typename>(trnd_<typename> L)
void ALLOC_FREE_TR(TN)(NODE_TR(TN)* l) {
    free(l->value);
    if (l->left!=NULL) {ALLOC_FREE_TR(TN)(l->left);}
    if (l->right!=NULL) {ALLOC_FREE_TR(TN)(l->right);}
    free(l);
}

#endif
