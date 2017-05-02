//Methods that allow string manipulation

#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "strinfo.h"

#define _GET_SUBSTRING_OVERLOAD(_1,_2,_3,_N,...) _N 
#define substr(...)  _GET_SUBSTRING_OVERLOAD(\
        __VA_ARGS__,\
        substr3,\
        substr2 ) (__VA_ARGS__)

//Duplicates string
string cpstr(string str);

//Return Roman representation of an integer
void inttrome(int num,string result,int length);

//Returns a lowercase version of the string
string lowercase(string str);

//Return an allocated, non-whitespace version of string str
string rmspace(string str);

//Gets substring with length characters from index start
//This function is can be called by substr function with the same signature
string substr3(string str,int start,int length);

//Gets substring from index start to the end of str
//This function is can be called by substr function with the same signature
string substr2(string str,int start);

//Returns a uppercase version of the string
string uppercase(string str);

#include "strutils.c"

#endif
