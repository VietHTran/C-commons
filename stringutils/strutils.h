//Methods that allow string manipulation

#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "strinfo.h"

//Duplicates string
string clone_str(string str);

//Gets substring with length characters from index start
//This function is can be called by substring function with the same signature
string substring3(string str,int start,int length);

//Gets substring from index start to the end of str
//This function is can be called by substring function with the same signature
string substring2(string str,int start);

//Returns a lowercase version of the string
string lowercase(string str);

//Returns a uppercase version of the string
string uppercase(string str);

#define _GET_SUBSTRING_OVERLOAD(_1,_2,_3,_N,...) _N 
#define substring(...)  _GET_SUBSTRING_OVERLOAD(\
        __VA_ARGS__,\
        substring3,\
        substring2 ) (__VA_ARGS__)

#include "strutils.c"

#endif
