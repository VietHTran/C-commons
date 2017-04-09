//queue's methods' definition

//creates a new storage for queue data structure in the heap memory and returns its pointer
//declaration: q_<typename>* mkq_<typname>(); 
QUEUE(TN)* MAKE_QUEUE(TN)(){
    QUEUE(TN)* Q=(QUEUE(TN)*)malloc(sizeof(QUEUE(TN)));
    Q->tail=NULL;
    Q->front=NULL;
    return Q;
}

//pushes new value into queue
//declaration: void enq_<typename>(q_<typename>* Q, <type> value);
void ENQUEUE(TN)(QUEUE(TN)* Q, T value) {
    assert(Q != NULL);

    NODE(TN)* holder=MAKE(TN)(value);

    if (Q->front==NULL) {
        Q->front=holder;
    } else {
        Q->tail->next=holder;
    }
    Q->tail=holder;
}

//removes the oldest value from queue and returns it
//declaration: <type> deq_<typename>(q_<typename>* Q);
T DEQUEUE(TN)(QUEUE(TN)* Q) {
    assert(Q!=NULL && Q->front!=NULL);

    NODE(TN)* holder=Q->front;
    T val;
#ifdef STR
    val=clone_str(holder->value);
    free(holder->value);
#else
    val=holder->value;
#endif
    Q->front=Q->front->next;
    free(holder);

    return val;
}

//gets the oldest value in queue
//declaration: <type> pkq_<typename>(q_<typename>* Q);
T PEEK_QUEUE(TN)(QUEUE(TN)* Q) {
    assert(Q!=NULL && Q->front!=NULL);
#ifdef STR
    return clone_str(Q->front->value);
#else
    return Q->front->value;
#endif
}

//checks if queue is empty
//declaration: bool eq_<typename>(q_<typename>* Q);
bool EMPTY_QUEUE(TN)(QUEUE(TN)* Q) {
    return Q->front==NULL;
}

//frees queue and its elements
//declaration: void fq_<typename>(q_<typename>* Q);
void FREE_QUEUE(TN)(QUEUE(TN)* Q) {
    assert(Q!=NULL);

    if (!EMPTY_QUEUE(TN)(Q)) {
        FREE(TN)(Q->front);
    }

    free(Q);
}
