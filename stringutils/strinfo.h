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

//Checks if str ends with prefix
bool ends_with_str(string str,string suffix);

#include "strinfo.c"

#endif
