//Generic queue implementation
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linkedlist.h"

#define QUEUE(TYPE_NAME) CAT(queue_,TYPE_NAME)
#define NEW_QUEUE(TYPE_NAME) CAT(new_queue_, TYPE_NAME)
#define FREE_QUEUE(TYPE_NAME) CAT(free_queue_, TYPE_NAME)
#define DEQUEUE(TYPE_NAME) CAT(dequeue_, TYPE_NAME)
#define ENQUEUE(TYPE_NAME) CAT(enqueue_, TYPE_NAME)
#define PEEK_QUEUE(TYPE_NAME) CAT(peek_queue_, TYPE_NAME)
#define EMPTY_QUEUE(TYPE_NAME) CAT(is_empty_queue_, TYPE_NAME)

//queue definition
struct QUEUE(TN) {
    NODE(TN)* tail;
    NODE(TN)* front;
    int length;
};

typedef struct QUEUE(TN) QUEUE(TN);

//creates a new storage for queue data structure in the heap memory and returns its pointer
QUEUE(TN)* NEW_QUEUE(TN)();

//pushes new value into queue
void ENQUEUE(TN)(QUEUE(TN)* S, T value);

//removes the oldest value from queue and returns it
T DEQUEUE(TN)(QUEUE(TN)* S);

//gets the oldest value in queue
T PEEK_QUEUE(TN)(QUEUE(TN)* S);

//checks if queue is empty
bool EMPTY_QUEUE(TN)(QUEUE(TN)* S);

//frees queue and its elements
void FREE_QUEUE(TN)(QUEUE(TN)* S);

#include "queue.c"
