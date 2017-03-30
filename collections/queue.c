//queue's methods' definition

//creates a new storage for queue data structure in the heap memory and returns its pointer
QUEUE(TN)* NEW_QUEUE(TN)(){
    QUEUE(TN)* S=(QUEUE(TN)*)malloc(sizeof(QUEUE(TN)));
    S->tail=NULL;
    S->front=NULL;
    return S;
}

//pushes new value into queue
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

//removes the oldest value from queue and returns it
T DEQUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL && S->front!=NULL);

    NODE(TN)* holder=S->front;
    T val;
#ifdef STR
    val=clone_str(holder->value);
    free(holder->value);
#else
    val=holder->value;
#endif
    S->front=S->front->next;
    free(holder);

    return val;
}

//gets the oldest value in queue
T PEEK_QUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL && S->front!=NULL);
#ifdef STR
    return clone_str(S->front->value);
#else
    return S->front->value;
#endif
}

//checks if queue is empty
bool EMPTY_QUEUE(TN)(QUEUE(TN)* S) {
    return S->front==NULL;
}

//frees queue and its elements
void FREE_QUEUE(TN)(QUEUE(TN)* S) {
    assert(S!=NULL);

    if (!EMPTY_QUEUE(TN)(S)) {
        FREE(TN)(S->front);
    }

    free(S);
}
