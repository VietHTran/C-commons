#include <stdlib.h>
#include <stdbool.h>
#include <../../generic.h>

struct node {
    char val[1024];
    struct node* next;
};

typedef struct node node;

struct stack_t {
    node* val;
    int length;
};

typedef struct stack_t* stack_t;

stack_t stack_new();
void push(stack_t S, char* value);
char* pop(stack_t S);
char* peek(stack_t S);
void freeStack(stack_t S);
bool isEmpty(stack_t S);
int len(char* str);
