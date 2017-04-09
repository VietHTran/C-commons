//Generics dynamic array implementation
#include <stdlib.h>
#include <stdbool.h>
#include "../generics.h"

#define LIST(TYPE_NAME) CAT(lst_,TYPE_NAME)
#define MAKE_LIST(TYPE_NAME) CAT(mklst_,TYPE_NAME)
#define FREE_LIST(TYPE_NAME) CAT(flst_, TYPE_NAME)
#define AT_LIST(TYPE_NAME) CAT(alst_,TYPE_NAME)
#define SET_LIST(TYPE_NAME) CAT(slst_,TYPE_NAME)
#define APPEND_LIST(TYPE_NAME) CAT(plst_,TYPE_NAME)
#define INSERT_LIST(TYPE_NAME) CAT(ilst_,TYPE_NAME)
#define REMOVE_LIST(TYPE_NAME) CAT(rmlst_,TYPE_NAME)
#define POP_LIST(TYPE_NAME) CAT(olst_,TYPE_NAME)
#define COUNT_LIST(TYPE_NAME) CAT(clst_,TYPE_NAME)

//Dynamic array definitions
//type: lst_<typename>
typedef struct LIST(TN) {
    T* arr;
    int size; //don't change this manually
} LIST(TN);

//creates a new storage for list in the heap memory and returns its pointer
//declaration: lst_<typename>*  mklst_<typename>();
LIST(TN)* MAKE_LIST(TN)();

//frees list and its elements
//declaration: void flst_<typename>(lst_<typname>* L);
void FREE_LIST(TN)(LIST(TN)* L);

//gets value from list at specified index
//declaration: <type> alst_<typename>(lst_<typename>* L, int index);
T AT_LIST(TN)(LIST(TN)* L, int index);

//sets value from list at specified index
//declaration: void slst_<typename>(lst_<typename>* L, <type> value, int index);
void SET_LIST(TN)(LIST(TN)* L, T value, int index);

//appends new value into list
//declaration: void plst_<typename>(lst_<typename>* L, <type> value);
void APPEND_LIST(TN)(LIST(TN)* L, T value);

//inserts new value into list at specified index
//declaration: void ilst_<typename>(lst_<typename>* L, <type> value, int index);
void INSERT_LIST(TN)(LIST(TN)* L, T value, int index);

//removes and returns value from list at specified index
//declaration: <type> rmlst_<typename>(lst_<typename>* L, int index);
T REMOVE_LIST(TN)(LIST(TN)* L, int index);

//removes and returns last value in the list
//declaration: <type> olst_<typename>(lst_<typename>* L);
T POP_LIST(TN)(LIST(TN)* L);

//returns the number of elements in list
//declaration: int clst_<typename>(lst_<typename>* L);
int COUNT_LIST(TN)(LIST(TN)* L);

#include "list.c"
