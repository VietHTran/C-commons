//Methods that allow string manipulation

#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdlib.h>
#include <string.h>
#include "strinfo.h"

//Duplicates string
string clone_str(string str);

//Get substring with (length) characters from index start
string substring(string str,int start,int length);

#include "strutils.c"

#endif
