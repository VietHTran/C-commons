//stack's methods' definitions

//creates a new storage for stack data structure in the heap memory and returns its pointer
//declaration: stk_<typename>* mkstk_<typename>();
STACK(TN)* MAKE_STACK(TN)(){
    STACK(TN)* S=(STACK(TN)*)malloc(sizeof(STACK(TN)));
    S->value=NULL;
    return S;
}

//pushes new value into stack
//declaration: void pstk_<typename>(stk_<typename>* S, <type> value);
void PUSH_STACK(TN)(STACK(TN)* S, T value) {
    assert(S != NULL);
    NODE(TN)* holder=MAKE(TN)(value);
    holder->next=S->value;
    S->value=holder;

}

//removes the latest value from the stack
//declaration: <type> rmstk_<typename>(stk_<typename>* S);
T POP_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL && S->value!=NULL);
    NODE(TN)* holder=S->value;
    T val;
    val=holder->value;

    S->value=S->value->next;
    free(holder);

    return val;
}

//gets the latest value of the stack without removing it
//declaration: <type> pkstk_<typename>(stk_<typename>* S);
T PEEK_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL && S->value!=NULL);

    return S->value->value;
}

//checkes if stack is empty from the memory
//declaration: bool estk_<typename>(stk_<typename>* S);
bool EMPTY_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL);
    return S->value==NULL;
}

//frees stack 
//declaration: void fstk_<typename>(stk_<typename>* S)
void FREE_STACK(TN)(STACK(TN)* S) {
    assert(S!=NULL);

    if (EMPTY_STACK(TN)(S)) {
        free(S);
        return;
    }

    FREE(TN)(S->value);
    free(S);
}

#ifdef ALLOC_T //T used allocated type

//frees stack and its elements which uses allocated memory
//declaration: void afstk_<typename>(stk_<typename>* S)
void ALLOC_FREE_STACK(TN)(STACK(TN)* S){
    assert(S!=NULL);

    if (EMPTY_STACK(TN)(S)) {
        free(S);
        return;
    }
    ALLOC_FREE(TN)(S->value);
    free(S);
}

#endif
