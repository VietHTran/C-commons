#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//creates a new storage for list in the heap memory and returns its pointer
//declaration: lst_<typename>* mklst_<typename>();
LIST(TN)* MAKE_LIST(TN)(){
    LIST(TN)* result=(LIST(TN)*)malloc(sizeof(LIST(TN)));
    result->size=0;
    result->arr=(T*)malloc(sizeof(T));
    result->arr[0]='\0';
    return result;
}

//frees list and its elements
//declaration: void flst_<typename>(lst_<typname>* L);
void FREE_LIST(TN)(LIST(TN)* L) {
    assert(L!=NULL);

#ifdef ALLOC_T //T uses allocated memory
    for (int i=0;i<L->size;i++) {
        free(L->arr[i]);
    }
#endif

    free(L->arr);
    free(L);
}

//gets value from list at specified index
//declaration: <type> glst_<typename>(lst_<typename>* L, int index);
T GET_LIST(TN)(LIST(TN)* L, int index) {
    assert(L!=NULL);
    assert(L->size>index);
    assert(index>=0);
    return L->arr[index];
}

//sets value from list at specified index
//declaration: void slst_<typename>(lst_<typename>* L, <type> value, int index);
void SET_LIST(TN)(LIST(TN)* L, T value, int index) {
    assert(L!=NULL);
    assert(L->size>index);
    assert(index>=0);

#ifdef ALLOC_T //T uses allocated memory
    free(L->arr[index]);
#endif

    L->arr[index]=value;
}

//appends new value into list
//declaration: void alst_<typename>(lst_<typename>* L, <type> value);
void APPEND_LIST(TN)(LIST(TN)* L, T value) {
    assert(L!=NULL);
    ++L->size;
    L->arr=(T*)realloc(L->arr,L->size*sizeof(T));
    L->arr[L->size-1]=value;
}

//inserts new value into list at specified index
//declaration: void ilst_<typename>(lst_<typename>* L, <type> value, int index);
void INSERT_LIST(TN)(LIST(TN)* L, T value, int index) {
    assert(L!=NULL);
    assert(L->size>=index);
    assert(index>=0);
    ++L->size;
    L->arr=(T*)realloc(L->arr,L->size*sizeof(T));
    
    for (int i=L->size-1;i>index;i--) {
        L->arr[i]=L->arr[i-1];
    }

    L->arr[index]=value;
}

//removes and returns value from list at specified index
//declaration: <type> rmlst_<typename>(lst_<typename>* L, int index);
T REMOVE_LIST(TN)(LIST(TN)* L, int index) {
    assert(L!=NULL);
    assert(L->size>index);
    assert(index>=0);

    T value=L->arr[index];

    for (int i=index;i<L->size-1;i++) {
        L->arr[i]=L->arr[i+1];
    }

    --L->size;
    L->arr[L->size]='\0';

    return value;
}

//removes and returns last value in the list
//declaration: <type> plst_<typename>(lst_<typename>* L);
T POP_LIST(TN)(LIST(TN)* L) {
    assert(L!=NULL);
    assert(L->size>0);

    --L->size;
    T value=L->arr[L->size];
    L->arr[L->size]='\0';

    return value;
}

//returns the number of elements in list
//declaration: int clst_<typename>(lst_<typename>* L);
int COUNT_LIST(TN)(LIST(TN)* L) {
    assert(L!=NULL);
    return L->size;
}

//--------Preprocessor for slclst functions----------------------
#define GET_PTR_SLCLST() do {                                   \
    arr_ptr[arr_index]=&L->arr[i];                              \
    ++arr_index;                                                \
} while (0)
//---------------------------------------------------------------

//returns an allocated array of pointers to specified elements in the list
//elements are chosen based on index from start (inclusive) to end (exclusive) with
//steps increment
//declaration: <type>** slclst_<typename>(lst_<typename>* L,int start,int end,int steps);
T** SLICE_LIST(TN)(LIST(TN)* L,int start,int end,int steps){
    assert(L!=NULL);
    assert(end>=-1  && end<=L->size);
    assert(start>=0 && start<L->size);
    int length=end-start,arr_index=0;
    bool is_forward=length>0;
    length/=steps;
    T** arr_ptr=(T**)malloc((length+1)*sizeof(T*));
    if (length==0) {return NULL;}
    if (is_forward) {
        assert(steps>0);
        for (int i=start;i<end;i+=steps) {GET_PTR_SLCLST();}
    } else {
        assert(steps<0);
        for (int i=start;i>end;i+=steps) {GET_PTR_SLCLST();}
    }
    arr_ptr[length]=NULL;
    return arr_ptr;
}

