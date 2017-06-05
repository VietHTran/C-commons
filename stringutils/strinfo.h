//Methods that gets information about the string (string)

#ifndef STRINFO_H
#define STRINFO_H

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>
#include "strgeneral.h"
#include "../generics.h"

#define INDEX_OF_3ARGS(_1,_2,_3) _Generic((_2),\
        char:instr,\
        char*:insubstr)(_1,_2,_3)

#define INDEX_OF_2ARGS(_1,_2) _Generic((_2),\
        char:istr_basic,\
        char*:isubstr) (_1,_2) 

#define _GET_INDEX_OF_OVERLOAD(_1,_2,_3,_N,...) _N

#define istr(...) _GET_INDEX_OF_OVERLOAD(\
        __VA_ARGS__,\
        INDEX_OF_3ARGS,\
        INDEX_OF_2ARGS ) (__VA_ARGS__)

//const string EMAIL_REGEX="^.+@.+\\..+$";
const string EMAIL_REGEX="^.+[@].+\\..+$";

//Returns the first index that has c character in the string str starting from index. 
//Returns -1 if not found.
//Can be used by calling istr with the same signature
int instr(string str, char c, int index);

//Returns the index within str of the first occurrence of the substring subi, starting at specified index.
//Return -1 if not found
//Can be used by calling istr with the same signature
int insubstr(string str,string sub, int index);

//Returns the first index that has c character in the string str
//Returns -1 if not found.
//Can be used by calling istr with the same signature
int istr_basic(string str, char c);

//Returns the index within str of the first occurrence of the substring sub.
//Return -1 if not found
//Can be used by calling istr with the same signature
int isubstr(string str,string sub);

//Check if string only consists of digits
bool isdgt(string str);

//Checks if contains only alphabetic characters
bool iswrd(string str);

//Returns length of string
int lenstr(string str);

//Checks if str ends with suffix 
bool sffxstr(string str,string suffix);

//Checks if email is valid
bool vdemail(string email);

#include "strutils.h"
#include "strinfo.c"

#endif
