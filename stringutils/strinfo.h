//Methods that gets information about the string (string)

#ifndef STRINFO_H
#define STRINFO_H

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strgeneral.h"

//Returns length of string
int len_str(string str);

//Checks if contains only alphabetic characters
bool is_word(string str);

//Checks if str ends with suffix 
bool ends_with_str(string str,string suffix);

//Check if string only consists of digits
bool is_digit(string str);

//Returns the first index that has c character in the string str
//Returns -1 if not found.
//Can be used by calling index_of_str for short
int index_of_str_basic(string str, char c);

//Returns the first index that has c character in the string str starting from index. 
//Returns -1 if not found.
//Can be used by calling index_of_str for short
int index_of_n_str(string str, char c, int index);

//Returns the index within str of the first occurrence of the substring sub.
//Return -1 if not found
//Can be used by calling index_of_str for short
int index_of_str_sub(string str,string sub);

//Returns the index within str of the first occurrence of the substring subi, starting at specified index.
//Return -1 if not found
//Can be used by calling index_of_str for short
int index_of_n_str_sub(string str,string sub, int index);

#define INDEX_OF_3ARGS(_1,_2,_3) _Generic((_2),\
        char:index_of_n_str,\
        char*:index_of_n_str_sub)(_1,_2,_3)

#define INDEX_OF_2ARGS(_1,_2) _Generic((_2),\
        char:index_of_str_basic,\
        char*:index_of_str_sub) (_1,_2) 

#define _GET_INDEX_OF_OVERLOAD(_1,_2,_3,_N,...) _N

#define index_of_str(...) _GET_INDEX_OF_OVERLOAD(\
        __VA_ARGS__,\
        INDEX_OF_3ARGS,\
        INDEX_OF_2ARGS ) (__VA_ARGS__)

#include "strutils.h"
#include "strinfo.c"

#endif
