#include "stack.h"
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

int len(char* str) {
    if (str==NULL) {
        return 0;
    }
    int i=0;
    while (str[i]!='\0') {
        i++;
    }
    return i;
}

bool stack_empty(stack_t S) {
    assert(S!=NULL);
    return S->length==0;
}

stack_t stack_new() {
    stack_t S=(stack_t)malloc(sizeof(struct stack_t));
    S->val=NULL;
    S->length=0;
    return S;
}

void push(stack_t S, char* value) {
    assert(S!=NULL);
    int length=len(value);
    node* holder=(node*)malloc(sizeof(node));
    //holder->val=(char*)malloc(length+1);
    strcpy(holder->val,value);
    holder->next=S->val;
    S->val=holder;

    ++S->length;
}

char* pop(stack_t S) {
    assert(S!=NULL && S->length>0);
    --S->length;
    
    node* holder=S->val;
    char* val=(char*)malloc((len(S->val->val)+1)*sizeof(char));
    strcpy(val,S->val->val);
    S->val=S->val->next;
    free(holder);

    return val;
}

char* peek(stack_t S) {
    assert(S!=NULL);
    char* top=(char*)malloc((len(S->val->val)+1)*sizeof(char));
    strcpy(top,S->val->val);
    return top;
}

bool isEmpty(stack_t S) {
    assert(S!=NULL);
    return S->length==0;
}

void freeStack(stack_t S) {
    assert(S!=NULL);
    if (isEmpty(S)) {
        free(S);
        return;
    }
    node* holder=S->val;
    while (holder!=NULL) {
        node* i=holder;
        holder=holder->next;
        free(i->val);
        free(i);
    }
    free(S);
}

